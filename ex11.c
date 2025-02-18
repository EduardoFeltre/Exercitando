#include <stdio.h>

    int main(){

        float salario_minimo, kilowatt_gasto;
        float valor_100kWh, valor_kWh, valor_a_pagar, valor_com_desconto;

        printf("Digite o valor do salario minimo:\n");
        scanf("%f", &salario_minimo);
        printf("Quantos kWh foram gastos na residencia:\n");
        scanf("%f", &kilowatt_gasto);

        valor_100kWh = salario_minimo / 7;
        valor_kWh = valor_100kWh / 100;
        valor_a_pagar = valor_kWh * kilowatt_gasto;
        valor_com_desconto = valor_a_pagar * 0.9;

        printf("Valor de 1 kWh: R$ %.2f\n", valor_kWh);
        printf("Valor a ser pago pela residencia R$ %.2f\n", valor_a_pagar);
        printf("Valor com 10%% de desconto: R$ %.2f\n", valor_com_desconto);


        return 0;

    }