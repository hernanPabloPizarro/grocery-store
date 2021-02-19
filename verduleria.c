# include<stdio.h>
# include<stdlib.h>

void encabezado(){
	printf("|***La Verduleria***|\n|***De Cleotilda****|\n\n");
}
int main(){
	int b=0,a,c=0,stk;;
	char *item[6]={"Papa","Tomate","Lechuga","Zanahoria","Cebolla","Acelga"};
	int producto=0;
	int i=0;
	float cuenta[6]={0,0,0,0,0,0};
	float precios[6];
	float stock[6];
	float peso=0;
	float cuentaTotal=0;
	float pago=0;
	float facturacion[6];
	float facturacionTotal;
	
	FILE *fp;
	fp=fopen("archivo.txt","r");
	for(i=0;i<6;i++) fscanf(fp,"%f",&precios[i]);
	for(i=0;i<6;i++) fscanf(fp,"%f",&stock[i]);
	for(i=0;i<6;i++) fscanf(fp,"%f ",&facturacion[i]);
	fscanf(fp,"%f ",&facturacionTotal);
	fclose(fp);
	
	do{
	system("cls");	
	encabezado();
	printf("Menu general\n");
	printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n",
	"1- Ingresar venta",
	"2- Ver lista de precios y stock",
	"3- Ver la cuenta actual",
	"4- Cobrar",
	"5- Sistema",
	"6- Salir");				//Opciones
	if(cuentaTotal!=0) printf("\n**Venta Pendiente\n\n");
	printf("Opcion: ");
	scanf("%i",&a);
	switch(a){
		
		case 1:
			do{
			system("cls");
			encabezado();
			printf("Cual producto desea?\t-1 para finalizar\n\t\t\t-2 para anular producto\n\n");
			printf("Producto\r\t\tPrecio\tCuenta\tStock\n\n");
			for(i=0;i<6;i++) printf("%i. %s\r\t\t%.2f\t%.2f\t%.2f\n",i+1,item[i],precios[i],cuenta[i],stock[i]);
			printf("\nTotal: \t\t%.2f\n",cuentaTotal);
			printf("Producto: ");
			scanf("%i",&producto);
			
			while(producto<-2||producto>6){
				printf("Opcion incorrecta\nIntente nuevamente: ");
				scanf("%i",&producto);
				if (producto==-1)break;
			}
			if (producto==-1)break;
			if (producto==-2)break;
			printf("\nCantidad de kilos de %s?: ",item[producto-1]);
			scanf("%f",&peso);
			
			if(peso>stock[producto-1]){
				printf("No contamos con mercaderia suficiente.\n");
			}else{
			stock[producto-1]-=peso;
			cuenta[producto-1]+=peso*precios[producto-1];
			printf("\nVenta de %.2f kilos de %s. Total: %.2f\n\n",peso,item[producto-1],cuenta[producto-1]);
			}
			
			cuentaTotal=0;
			for(i=0;i<6;i++) cuentaTotal+=cuenta[i];
			system("pause");
			}while(producto!=-1);
			
			if (producto==-2){
				do{
				system("cls");
				encabezado();
				printf("Cual producto desea anular?: \t-1=Salir\n\n\n");
				printf("Producto\r\t\tPrecio\tCuenta\n\n");
				for(i=0;i<6;i++) printf("%i. %s\r\t\t%.2f\t%.2f\n",i+1,item[i],precios[i],cuenta[i]);
				printf("Producto?: ");
				scanf("%i",&producto);
				stock[producto-1]+=cuenta[producto-1]/precios[producto-1];
				cuenta[producto-1]=0;
				}while(producto!=-1);
				cuentaTotal=0;
				for(i=0;i<6;i++) cuentaTotal+=cuenta[i];
				
				
			}
			break;
	
		case 2:
			system("cls");
			encabezado();
			printf("Lista de precios:\n\n");
			printf("\tProducto\r\t\t\tPrecio\tStock\n\n");
			for(i=0;i<6;i++)printf("\t%s:\r\t\t\t%.2f\t%.2f\n", item[i],precios[i],stock[i]);
			printf("\n");
			system("pause");
			
			break;
			
		case 3:
			system("cls");
			encabezado();
			printf("Cuenta actual:\n\n");
			if(cuentaTotal==0) printf("No hay valores que mostrar\n\n");
			else{
			printf("\tProducto\tMonto\n\n");
			for(i=0;i<6;i++)printf("\t%s:\r\t\t\t%.2f\n", item[i],cuenta[i]);
			printf("\nTotal: %.2f\n\n",cuentaTotal);
			}
			
			
			system("pause");
			break;
			
		case 4:
			system("cls");
			encabezado();
			if(cuentaTotal!=0){
			for(i=0;i<6;i++) printf("%s:\r\t\t %.2f\n",item[i],cuenta[i]);
			
			printf("\nSu cuenta es de %.2f\nCon cuanto abona?: ",cuentaTotal);
			scanf("%f",&pago);
			while(pago<cuentaTotal){
				printf("Monto insuficiente\nIntente de nuevo: ");
				scanf("%f",&pago);
			}
			printf("Su vuelto es de: %.2f\nMuchas gracias\n",pago-cuentaTotal);
			for(i=0;i<6;i++) facturacion[i]+=cuenta[i];
			for(i=0;i<6;i++) cuenta[i]=0;
			peso=0;
			cuentaTotal=0;
			pago=0;
			}
			else 
			printf("Aun no ha ingresadoventa\n\n");
			system("pause");
			
		
			break;
		case 5:
			do{
			c=0;	
			system("cls");
			encabezado();
			printf("Opciones de Sistemas\n");
			printf("\t%s\n\t%s\n\t%s\n\t%s\n","1-Stock","2-Facturacion","3-Cambiar Precios","4-Salir de Sistemas");
			printf("Opcion: ");
			scanf("%i",&a);
			switch (a){
				case 1:
					system("cls");
					encabezado();
					printf("Stock\n");
					
					printf("\nQue desea hacer?\n\t1=redefinir Stock\n\t2=agregar Stock\n");
					scanf("%i",&stk);
					
					if(stk==1){
						do{
							system("cls");
							encabezado();
							printf("Que producto se redefine? -1 salir:\n");
							for(i=0;i<6;i++) printf("%i- %s:\r\t\t%.2f\n",i+1,item[i],stock[i]);
							printf("\nProducto:");
							scanf("%i",&producto);
							while(producto<-1||producto>6){
								printf("Opcion incorrecta\nIntente nuevamente: ");
								scanf("%i",&producto);
							}
							if(producto==-1)break;
							printf("Cual es el nuevo valor?: ");
							scanf("%f",&stock[producto-1]);
						}while(producto!=-1);
					}
					if(stk==2){
						do{
							system("cls");
							encabezado();
							printf("Cual producto agregamos stock? -1 salir:\n");
							for(i=0;i<6;i++) printf("%i- %s:\r\t\t%.2f\n",i+1,item[i],stock[i]);
							printf("\nProducto:");
							scanf("%i",&producto);
							while(producto<-1||producto>6){
								printf("Opcion incorrecta\nIntente nuevamente: ");
								scanf("%i",&producto);
							}
							if(producto==-1)break;
							printf("Cuanto agregamos?: ");
							float masStock;
							scanf("%f",&masStock);
							stock[producto-1]+=masStock;
							
						}while(producto!=-1);
					}
					break;
				case 2:
					system("cls");
					encabezado();
					printf("Facturacion\n\n");
					for(i=0;i<6;i++)printf("%s:\r\t\t%.2f\n",item[i],facturacion[i]);
					facturacionTotal=0;
					for(i=0;i<6;i++)facturacionTotal+=facturacion[i];
					printf("\nFacturacion total: %.2f\n",facturacionTotal);
					system("pause");
					break;
				case 3:
					do{
					system("cls");
					encabezado();
					printf("\tPrecios\n");
					printf("\nCual producto desea cambiar precio\n-1 finalizar\n\n");
					for(i=0;i<6;i++)printf("%i- %s:\r\t\t%.2f\n",i+1,item[i],precios[i]);
					printf("Producto?: ");
					scanf("%i",&producto);
					while(producto<-1||producto>6){
								printf("Opcion incorrecta\nIntente nuevamente: ");
								scanf("%i",&producto);
							}
					if(producto==-1)break;
					printf("Precio nuevo?: ");
					scanf("%f",&precios[producto-1]);
					}while(producto!=-1);
					break;
				case 4:
					system("cls");
					encabezado();
					printf("Salir de Sistemas?\n1=si\n");
					scanf("%i",&c);
					
					fp=fopen("archivo.txt","w");
					for(i=0;i<6;i++) fprintf(fp,"%.2f ",precios[i]);
					fprintf(fp,"\n");
					for(i=0;i<6;i++) fprintf(fp,"%.2f ",stock[i]);
					fclose(fp);
					break;
			}
			}while(c!=1);
			break;
			
		case 6:
			fp=fopen("archivo.txt","w");
					for(i=0;i<6;i++) fprintf(fp,"%.2f ",precios[i]);
					fprintf(fp,"\n");
					for(i=0;i<6;i++) fprintf(fp,"%.2f ",stock[i]);
					fprintf(fp,"\n");
					for(i=0;i<6;i++) fprintf(fp,"%.2f ",facturacion[i]);
					fprintf(fp,"%.2f ",facturacionTotal);
					fclose(fp);
			printf("Seguro desea salir?\n1=si\nO presione tecla \"Ctrl\" + \"C\"\n");
			scanf("%i",&b);
			break;
		default:
			printf("opcion incorrecta\n");
			Sleep(600);
			break;
	}
	}while(b!=1);
	return 0;
}
