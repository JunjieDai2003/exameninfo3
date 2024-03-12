#include<stdio.h>
#include<malloc.h>
typedef struct
{
	float yuan;
	float wones;
	float SingDolar;
}DIVISA;
typedef struct
{
	char nya[20];
	int ID;
	float saldo;
	int flag;
	DIVISA sdivisa;
}DCliente;
void IniCliente(DCliente*, int);
int VIPCliente(DCliente*, int);
int main()
{
	DCliente* c;
	int dim;
	printf("Dime uantos clientes quieres introducir");
	scanf_s("%d", &dim);
	c = (DCliente*)malloc(dim * sizeof( DCliente));
	IniCliente(c, dim);
	
}
void IniCliente(DCliente* c, int dim)
{
	int i;
	int best;
	for (i = 0; i < dim; i++)
	{
		printf("Nombre\n");
		getchar();
		gets_s((c + i)->nya);
		printf("ID\n");
		scanf_s("%d", &c[i].ID);
		printf("Saldo\n");
		scanf_s("%f", &c[i].saldo);
		printf("Yuan\n");
		scanf_s("%f", &c[i].sdivisa.yuan);
		printf("wones\n");
		scanf_s("%f", &c[i].sdivisa.wones);
		printf("SingDolar\n");
		scanf_s("%f", &c[i].sdivisa.SingDolar);
	}
	best = VIPCliente( c, dim);
	if (best != 10000)
	{
		printf("vip es NOmbre %s SSaldo %f Banco %f %f %f", c[best].nya, c[best].saldo, c[best].sdivisa.yuan, c[best].sdivisa.wones, c[best].sdivisa.SingDolar);
	}
}
int VIPCliente(DCliente*c, int dim)
{
	int i;
	int max = 0;
	int max1 = 0;
	float banco;
	int best;
	for (i = 0; i < dim; i++)
	{
		banco = c[i].sdivisa.yuan * 0.13 + c[i].sdivisa.wones * 0.0007 + c[i].sdivisa.SingDolar * 0.69;
		if (c[i].saldo < 1 || c[i].sdivisa.yuan < 1 || c[i].sdivisa.wones < 1 || c[i].sdivisa.SingDolar < 1)
		{
			c[i].flag = 0;
		}
		else
		{
			c[i].flag = 1;
		}
		if (c[i].flag == 1)
		{
			if (c[i].saldo > max && banco > max1)
			{
				best = i;
				max = c[i].saldo;
				max1 = banco ;
			}

		}
	}
	if (max == 0 || max1 == 0)
	{
		printf("NO hay vip\n");
		return 10000;
	}
	else
	{
		return best;
	}
}
