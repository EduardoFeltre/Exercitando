// ARDUINO CARRINHO AGRÍCOLA AUTÔNOMO - HW-394 30 PINOS
// Sistema de irrigação autônomo com comunicação Bluetooth e receptor MX-FS-03V
// MODIFICADO: Adicionado giro esquerda/direita e controle de velocidade por PWM

#include <SoftwareSerial.h>

// ========== DEFINIÇÕES DE PINOS - HW-394 30 PINOS ==========

// Motor do carrinho (apenas um motor com relé XY-J02)
#define MOTOR_RELE 2         // Controla o relé para ligar/desligar motor
#define MOTOR_DIRECAO 3      // Controla direção do motor (PWM para velocidade)

// Novos pinos para controle de giro (simulando diferencial)
#define MOTOR_ESQUERDA 5     // PWM para "motor" esquerda (ou servo para direção)
#define MOTOR_DIREITA 6      // PWM para "motor" direita (ou servo para direção)

// Sistema de irrigação
#define BOMBA_AGUA 4
#define HIGROMETRO_ANALOGICO A0
#define LED_STATUS 13

// Sensor ultrassônico para detecção simples
#define SENSOR_TRIG 7
#define SENSOR_ECHO 8

// Comunicação Bluetooth (HC-05/HC-06)
#define BT_RX 10
#define BT_TX 11

// Receptor MX-FS-03V (433MHz)
#define RECEPTOR_DATA 12  // Pino digital para receber sinal

// ========== CONSTANTES DE MOVIMENTO ==========
#define VELOCIDADE_BAIXA 80      // Velocidade reduzida (31% da máxima)
#define VELOCIDADE_MEDIA 120     // Velocidade média (47% da máxima)
#define VELOCIDADE_NORMAL 255    // Velocidade máxima
#define VELOCIDADE_PADRAO VELOCIDADE_BAIXA  // Usar velocidade baixa como padrão

#define TEMPO_MOVIMENTO_CURTO 800    // Reduzido para movimento mais suave
#define TEMPO_MOVIMENTO_LONGO 2000   // Reduzido
#define TEMPO_GIRO 600              // Tempo para giro de 90 graus aproximadamente
#define TEMPO_PAUSA_MOVIMENTO 1500   // Pausa entre movimentos
#define DISTANCIA_DETECCAO 30        // Distância para detecção simples

// Outras constantes
#define TEMPO_IRRIGACAO 5000      // 5 segundos de irrigação
#define UMIDADE_MINIMA 30         // Valor mínimo de umidade (0-100%)
#define TEMPO_PAUSA_IRRIGACAO 500 // Pausa após irrigação

// ========== VARIÁVEIS GLOBAIS ==========
bool sistema_ligado = false;
bool irrigando = false;
bool movendo = false;
bool sinal_umidade_recebido = false;
int ultima_leitura_umidade = 0;
int velocidade_atual = VELOCIDADE_PADRAO;
unsigned long ultimo_tempo_irrigacao = 0;
unsigned long ultimo_tempo_movimento = 0;

// Comunicação Bluetooth
SoftwareSerial bluetooth(BT_RX, BT_TX);

// ========== PROTÓTIPOS DE FUNÇÕES ==========
void inicializar_sistema(void);
void verificar_bluetooth(void);
void verificar_sinal_umidade(void);
void executar_irrigacao(void);
void mover_simples(void);
void ligar_motor(int velocidade = VELOCIDADE_PADRAO);
void desligar_motor(void);
void girar_esquerda(int tempo = TEMPO_GIRO);
void girar_direita(int tempo = TEMPO_GIRO);
void mover_frente(int tempo, int velocidade = VELOCIDADE_PADRAO);
bool detectar_obstaculo_simples(void);
int ler_umidade_solo(void);
bool precisa_irrigar(void);
void ligar_bomba(void);
void desligar_bomba(void);
void piscar_led_status(int vezes);
void movimento_automatico(void);
void desviar_obstaculo(void);

// ========== SETUP ==========
void setup() {
    Serial.begin(9600);
    inicializar_sistema();
    Serial.println("Sistema Carrinho Agricola Inicializado - Com Giro e Velocidade Controlada");
}

// ========== LOOP PRINCIPAL ==========
void loop() {
    verificar_bluetooth();
    
    if (sistema_ligado) {
        verificar_sinal_umidade();
        
        if (sinal_umidade_recebido && !irrigando && !movendo) {
            executar_irrigacao();
        }
        
        // Movimento simples quando não está irrigando
        if (!irrigando && (millis() - ultimo_tempo_movimento > 8000)) {
            movimento_automatico();
        }
    }
    
    delay(100); // Pequena pausa para estabilidade
}

// ========== INICIALIZAÇÃO ==========
void inicializar_sistema(void) {
    // Configurar motor com relé
    pinMode(MOTOR_RELE, OUTPUT);
    pinMode(MOTOR_DIRECAO, OUTPUT);
    
    // Configurar controle de giro
    pinMode(MOTOR_ESQUERDA, OUTPUT);
    pinMode(MOTOR_DIREITA, OUTPUT);
    
    // Configurar sensor ultrassônico
    pinMode(SENSOR_TRIG, OUTPUT);
    pinMode(SENSOR_ECHO, INPUT);
    
    // Configurar sistema de irrigação
    pinMode(BOMBA_AGUA, OUTPUT);
    pinMode(LED_STATUS, OUTPUT);
    pinMode(HIGROMETRO_ANALOGICO, INPUT);
    
    // Configurar receptor MX-FS-03V
    pinMode(RECEPTOR_DATA, INPUT);
    
    // Inicializar Bluetooth
    bluetooth.begin(9600);
    
    // Estado inicial
    sistema_ligado = false;
    irrigando = false;
    movendo = false;
    sinal_umidade_recebido = false;
    velocidade_atual = VELOCIDADE_PADRAO;
    
    desligar_motor();
    desligar_bomba();
    
    // Sinalizar inicialização
    piscar_led_status(3);
}

// ========== COMUNICAÇÃO BLUETOOTH ==========
void verificar_bluetooth(void) {
    if (bluetooth.available()) {
        String comando = bluetooth.readStringUntil('\n');
        comando.trim();
        
        if (comando == "LIGAR" || comando == "1") {
            sistema_ligado = true;
            bluetooth.println("SISTEMA_LIGADO");
            digitalWrite(LED_STATUS, HIGH);
            Serial.println("Sistema ligado via Bluetooth");
            
        } else if (comando == "DESLIGAR" || comando == "0") {
            sistema_ligado = false;
            desligar_motor();
            desligar_bomba();
            irrigando = false;
            movendo = false;
            bluetooth.println("SISTEMA_DESLIGADO");
            digitalWrite(LED_STATUS, LOW);
            Serial.println("Sistema desligado via Bluetooth");
            
        } else if (comando == "VEL_BAIXA") {
            velocidade_atual = VELOCIDADE_BAIXA;
            bluetooth.println("VELOCIDADE_BAIXA_ATIVADA");
            Serial.println("Velocidade baixa ativada");
            
        } else if (comando == "VEL_MEDIA") {
            velocidade_atual = VELOCIDADE_MEDIA;
            bluetooth.println("VELOCIDADE_MEDIA_ATIVADA");
            Serial.println("Velocidade média ativada");
            
        } else if (comando == "VEL_ALTA") {
            velocidade_atual = VELOCIDADE_NORMAL;
            bluetooth.println("VELOCIDADE_ALTA_ATIVADA");
            Serial.println("Velocidade alta ativada");
        }
    }
}

// ========== VERIFICAR SINAL DO RECEPTOR MX-FS-03V ==========
void verificar_sinal_umidade(void) {
    // Ler sinal digital do receptor MX-FS-03V
    int sinal_recebido = digitalRead(RECEPTOR_DATA);
    
    if (sinal_recebido == HIGH) {
        sinal_umidade_recebido = true;
        Serial.println("Sinal de umidade recebido do transmissor");
        piscar_led_status(2);
    } else {
        sinal_umidade_recebido = false;
    }
}

// ========== SISTEMA DE IRRIGAÇÃO ==========
void executar_irrigacao(void) {
    Serial.println("Iniciando processo de irrigacao");
    irrigando = true;
    
    // Parar movimento
    desligar_motor();
    
    // Verificar umidade local do solo
    int umidade_atual = ler_umidade_solo();
    Serial.print("Umidade do solo: ");
    Serial.print(umidade_atual);
    Serial.println("%");
    
    if (precisa_irrigar()) {
        Serial.println("Solo necessita irrigacao - Acionando bomba");
        ligar_bomba();
        
        // Irrigar por tempo determinado
        unsigned long inicio_irrigacao = millis();
        while (millis() - inicio_irrigacao < TEMPO_IRRIGACAO) {
            // Piscar LED durante irrigação
            digitalWrite(LED_STATUS, !digitalRead(LED_STATUS));
            delay(200);
        }
        
        desligar_bomba();
        Serial.println("Irrigacao concluida");
        
        // Pausa após irrigação
        delay(TEMPO_PAUSA_IRRIGACAO);
    } else {
        Serial.println("Solo ja possui umidade suficiente");
    }
    
    irrigando = false;
    sinal_umidade_recebido = false;
    ultimo_tempo_irrigacao = millis();
    digitalWrite(LED_STATUS, sistema_ligado ? HIGH : LOW);
}

int ler_umidade_solo(void) {
    int leitura_analogica = analogRead(HIGROMETRO_ANALOGICO);
    // Converter para porcentagem (0-100%)
    // Ajustar conforme calibração do seu higrômetro
    int umidade_percentual = map(leitura_analogica, 0, 1023, 0, 100);
    ultima_leitura_umidade = umidade_percentual;
    return umidade_percentual;
}

bool precisa_irrigar(void) {
    return (ultima_leitura_umidade < UMIDADE_MINIMA);
}

void ligar_bomba(void) {
    digitalWrite(BOMBA_AGUA, HIGH);
}

void desligar_bomba(void) {
    digitalWrite(BOMBA_AGUA, LOW);
}

// ========== MOVIMENTO COM GIRO E VELOCIDADE CONTROLADA ==========
void movimento_automatico(void) {
    if (irrigando) return;
    
    movendo = true;
    Serial.println("Iniciando movimento automatico com velocidade controlada");
    
    // Verificar se há obstáculo próximo
    if (detectar_obstaculo_simples()) {
        Serial.println("Obstaculo detectado - Executando desvio");
        desviar_obstaculo();
    } else {
        // Movimento aleatório: frente, esquerda ou direita
        int tipo_movimento = random(0, 4);
        
        switch (tipo_movimento) {
            case 0:
            case 1: // 50% chance de ir para frente
                Serial.println("Movendo para frente");
                mover_frente(TEMPO_MOVIMENTO_CURTO, velocidade_atual);
                break;
                
            case 2: // 25% chance de girar à esquerda
                Serial.println("Girando para esquerda");
                girar_esquerda(TEMPO_GIRO);
                delay(200);
                mover_frente(TEMPO_MOVIMENTO_CURTO / 2, velocidade_atual);
                break;
                
            case 3: // 25% chance de girar à direita
                Serial.println("Girando para direita");
                girar_direita(TEMPO_GIRO);
                delay(200);
                mover_frente(TEMPO_MOVIMENTO_CURTO / 2, velocidade_atual);
                break;
        }
        
        // Pausa entre movimentos
        delay(TEMPO_PAUSA_MOVIMENTO);
    }
    
    movendo = false;
    ultimo_tempo_movimento = millis();
}

void desviar_obstaculo(void) {
    Serial.println("Executando manobra de desvio");
    
    // Parar
    desligar_motor();
    delay(500);
    
    // Girar aleatoriamente para esquerda ou direita
    if (random(0, 2) == 0) {
        Serial.println("Desviando pela esquerda");
        girar_esquerda(TEMPO_GIRO * 1.5); // Giro maior para desvio
    } else {
        Serial.println("Desviando pela direita");
        girar_direita(TEMPO_GIRO * 1.5);
    }
    
    delay(300);
    
    // Mover um pouco para frente após o desvio
    mover_frente(TEMPO_MOVIMENTO_CURTO, velocidade_atual);
}

// ========== CONTROLE DE MOTOR COM VELOCIDADE ==========
void ligar_motor(int velocidade) {
    digitalWrite(MOTOR_RELE, HIGH);  // Liga o relé (motor ligado)
    analogWrite(MOTOR_DIRECAO, velocidade); // Controla velocidade via PWM
    Serial.print("Motor ligado - Velocidade: ");
    Serial.println(velocidade);
}

void desligar_motor(void) {
    digitalWrite(MOTOR_RELE, LOW);   // Desliga o relé (motor desligado)
    analogWrite(MOTOR_DIRECAO, 0);   // PWM em 0
    analogWrite(MOTOR_ESQUERDA, 0);  // Desliga controle esquerda
    analogWrite(MOTOR_DIREITA, 0);   // Desliga controle direita
    Serial.println("Motor desligado");
}

void mover_frente(int tempo, int velocidade) {
    digitalWrite(MOTOR_RELE, HIGH);
    analogWrite(MOTOR_DIRECAO, velocidade);
    analogWrite(MOTOR_ESQUERDA, velocidade);
    analogWrite(MOTOR_DIREITA, velocidade);
    
    delay(tempo);
    
    desligar_motor();
}

void girar_esquerda(int tempo) {
    Serial.println("Executando giro para esquerda");
    digitalWrite(MOTOR_RELE, HIGH);
    
    // Simula giro diferencial: lado direito mais rápido que esquerdo
    analogWrite(MOTOR_ESQUERDA, velocidade_atual / 3);  // Esquerda bem lenta
    analogWrite(MOTOR_DIREITA, velocidade_atual);       // Direita na velocidade normal
    analogWrite(MOTOR_DIRECAO, velocidade_atual / 2);   // Velocidade geral reduzida
    
    delay(tempo);
    desligar_motor();
}

void girar_direita(int tempo) {
    Serial.println("Executando giro para direita");
    digitalWrite(MOTOR_RELE, HIGH);
    
    // Simula giro diferencial: lado esquerdo mais rápido que direito
    analogWrite(MOTOR_ESQUERDA, velocidade_atual);      // Esquerda na velocidade normal
    analogWrite(MOTOR_DIREITA, velocidade_atual / 3);   // Direita bem lenta
    analogWrite(MOTOR_DIRECAO, velocidade_atual / 2);   // Velocidade geral reduzida
    
    delay(tempo);
    desligar_motor();
}

// ========== DETECÇÃO SIMPLES DE OBSTÁCULOS ==========
bool detectar_obstaculo_simples(void) {
    digitalWrite(SENSOR_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(SENSOR_TRIG, LOW);
    
    long duracao = pulseIn(SENSOR_ECHO, HIGH);
    float distancia = (duracao * 0.034) / 2;
    
    Serial.print("Distancia detectada: ");
    Serial.print(distancia);
    Serial.println(" cm");
    
    return (distancia > 0 && distancia < DISTANCIA_DETECCAO);
}

// ========== FUNÇÕES AUXILIARES ==========
void piscar_led_status(int vezes) {
    for (int i = 0; i < vezes; i++) {
        digitalWrite(LED_STATUS, HIGH);
        delay(200);
        digitalWrite(LED_STATUS, LOW);
        delay(200);
    }
}

// ========== COMANDOS BLUETOOTH ACEITOS ==========
/*
 * LIGAR ou 1        - Liga o sistema
 * DESLIGAR ou 0     - Desliga o sistema
 * VEL_BAIXA         - Define velocidade baixa (padrão)
 * VEL_MEDIA         - Define velocidade média
 * VEL_ALTA          - Define velocidade alta
 * 
 * O sistema é autônomo e não precisa de outros comandos.
 * Quando ligado, responde automaticamente aos sinais do 
 * transmissor MX-FS-03V conectado ao sensor de umidade.
 * 
 * NOVOS RECURSOS:
 * - Movimento com giro para esquerda e direita
 * - Controle de velocidade por PWM (baixa, média, alta)
 * - Sistema de desvio de obstáculos com giro
 * - Movimento aleatório mais inteligente
 */