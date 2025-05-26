import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.Locale;

public class SavingsSimulator {
    public static void main(String[] args) {
        // Configura o Locale para usar ponto como separador decimal
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        
        // --- Variaveis ---
        double metaPoupanca = 0, saldoAtual = 0, contribuicaoMensal = 0, taxaJurosAnual = 0;
        double saldoCorrente, jurosMensal, taxaJurosMensal;
        int meses = 0;
        boolean metadeMetaAlcancada = false;

        // --- Entrada de Dados ---
        System.out.println("--- Simulador de Meta de Poupanca ---");
        try {
            System.out.print("Digite sua meta de poupanca (R$): ");
            metaPoupanca = scanner.nextDouble();
            System.out.print("Digite seu saldo atual (R$): ");
            saldoAtual = scanner.nextDouble();
            System.out.print("Digite sua contribuicao mensal planejada (R$): ");
            contribuicaoMensal = scanner.nextDouble();
            System.out.print("Digite a taxa de juros anual estimada (%, ex: 5 para 5%): ");
            taxaJurosAnual = scanner.nextDouble();
        } catch (InputMismatchException e) {
            System.out.println("\nErro: Entrada invalida. Por favor, digite apenas numeros.");
            scanner.close();
            return;
        } catch (Exception e) {
            System.out.println("\nOcorreu um erro inesperado: " + e.getMessage());
            scanner.close();
            return;
        }

        // --- Validacao ---
        if (saldoAtual >= metaPoupanca) {
            System.out.println("\nParabens! Voce ja atingiu ou ultrapassou sua meta de poupanca.");
            scanner.close();
            return;
        }
        if (contribuicaoMensal <= 0 && (saldoAtual * (1 + (taxaJurosAnual / 100.0) / 12.0)) <= saldoAtual) {
            System.out.println("\nCom contribuicao mensal zero ou negativa e sem rendimentos, voce nao alcancara a meta.");
            scanner.close();
            return;
        }
        if (contribuicaoMensal < 0) {
            System.out.println("\nA contribuicao mensal nao pode ser negativa.");
            scanner.close();
            return;
        }

        // --- Calculo (Loop) ---
        saldoCorrente = saldoAtual;
        taxaJurosMensal = (taxaJurosAnual / 100.0) / 12.0;
        System.out.println("\n--- Simulacao Mes a Mes ---");
        
        while (saldoCorrente < metaPoupanca) {
            // Calcula juros do mes
            jurosMensal = saldoCorrente * taxaJurosMensal;
            
            // Adiciona juros e contribuicao
            saldoCorrente += jurosMensal;
            saldoCorrente += contribuicaoMensal;
            
            // Incrementa o contador de meses
            meses++;
            
            // Imprime status a cada 6 meses
            if (meses % 6 == 0) {
                System.out.printf("Mes %d: Saldo = R$ %.2f\n", meses, saldoCorrente);
            }
            
            // Mensagem Motivacional
            if (!metadeMetaAlcancada && saldoCorrente >= metaPoupanca / 2.0) {
                System.out.println("\n*** Otimo progresso! Voce ja passou da metade da sua meta! Continue assim! ***\n");
                metadeMetaAlcancada = true;
            }
            
            // Seguranca para evitar loop infinito
            if (meses > 12000) {
                System.out.println("\nA simulacao excedeu 1000 anos. Verifique os valores de entrada.");
                scanner.close();
                return;
            }
        }

        // --- Saida ---
        System.out.println("\n--- Resultado Final ---");
        System.out.printf("Parabens! Voce alcancara sua meta de R$ %.2f em:\n", metaPoupanca);
        
        int anos = meses / 12;
        int mesesRestantes = meses % 12;
        
        if (anos > 0) {
            System.out.printf("%d ano(s) ", anos);
        }
        if (mesesRestantes > 0) {
            System.out.printf("e %d mes(es)\n", mesesRestantes);
        }
        if (anos == 0 && mesesRestantes == 0) {
            System.out.println("menos de 1 mes (ou ja alcancado).");
        } else if (anos > 0 && mesesRestantes == 0) {
            System.out.println();
        }
        
        System.out.printf("Saldo final estimado: R$ %.2f\n", saldoCorrente);
        scanner.close();
    }
}