#include <stdio.h>
#include <stdlib.h>

typedef struct No {
   int valor;
   struct No *prox;
} TNo;

typedef TNo* TLista;

int menu ()
{
   int opcao;

   printf ("\nTABELA HASH: O PROGRAMA DO SÉCULO\n\n");
   printf ("\nMenu de Operacoes:\n\n");
   printf ("(1) Inserir\n");
   printf ("(2) Remover\n");
   printf ("(3) Alterar\n");
   printf ("(4) Buscar\n");
   printf ("(5) Exibir\n");
   printf ("(6) Sair\n\n");

   printf ("Entre com a sua opcao: ");
   scanf ("%d", &opcao);

   return opcao;
}

int alterar (TLista L, int velho, int novo)
{
   TLista aux = L;
   int cont = 0;

   while (aux)
   {
      if (aux->valor == velho)
      {
         aux->valor = novo;
         cont = 1;
         return cont;
      }

      aux = aux->prox;
   }

   return cont;
}

int buscar (TLista L, int numero)
{
   TLista aux = L;
   
   while (aux)
   {
      if (aux->valor == numero)
      {
         return 1;
      }
      aux = aux->prox;
   }

   return 0;
}

int inserir (TLista *L, int numero)
{
   TLista aux;
   aux = (TLista) malloc (sizeof(TNo));
   
   TNo* atual = *L;
   while (atual) {
         if (atual->valor == numero) {
               return 0; // Valor já existe na tabela, retornar 0 (inserção não realizada)
         }
         atual = atual->prox;
   }

   if (!aux)
   {
      return 0;
   }
   else
   {
         aux->valor = numero;
         aux->prox = *L;

         *L = aux;
         return 1;
   }
}

int verificando(TLista *L, int numero){
   TNo* atual = *L;
   while (atual) {
         if (atual->valor == numero) {
               return 0; // Valor já existe na tabela, retornar 0 (inserção não realizada)
         }
         atual = atual->prox;
   }
   return 1;
}

int numLista(int numero){
   int res;
   res = numero % 10;
   return res;
}

int remover (TLista *L, int numero)
{
   
   TLista pre, pos;
   int cont = 0;

   while ((*L) && ((*L)->valor == numero))
   {
      pre = *L;   

      *L = pre->prox;

      free (pre);
      
      cont = 1;

      return cont;
   } 
   
   if (*L)
   {

      pos = (*L)->prox;

      pre = *L;

      while (pos)
      {
         
         if (pos->valor == numero)
         {

            pre->prox = pos->prox;

            free (pos);

            cont = 1;	

            pos = pre->prox;

            return cont;
         }
         else
         {
            pre = pos;
            pos = pos->prox;
         }
      }
   }
   
   return cont;
}

void exibir (TLista L)
{
   
   TLista aux = L;

   if (!L)
   {
      printf ("Lista vazia!\n");
   }
   else
   {
      printf ("Valores: ");

      while (aux)
      {
         printf ("%d ", aux->valor);

         aux = aux->prox;
      }

      printf ("\n");
   }
}

int main(void) {
   TLista tabelahash[10] = {NULL};
   int i, j, num, num2, op, resp;

   do
      {
         op = menu ();
         switch (op)
         {
            case 1: printf ("\nDigite o valor pra ser inserido: ");
                        scanf ("%d", &num);

                        i = numLista(num);

                           if(verificando(&tabelahash[i], num) == 1){
                              (inserir(&tabelahash[i], num));
                              printf("\nInserção realizada com sucesso!");
                           } else {
                              printf("\nErro na inserção!");
                           }
                  break;

            case 2: printf ("\nDigite o valor que será removido: ");
                        scanf ("%d", &num);

                        i = numLista(num);
               
                        //chamando a função
                        resp = remover (&tabelahash[i], num);

                        if (resp == 1)
                        {
                           printf ("\n\tHouveram %d remoções!", resp);
                  }
                  else
                  {
                     printf ("\n\tRemoção não realizada!");
                  }
                  break;

            //Alteração
            case 3: printf ("\nEntre com o valor a ser alterado: ");
                        scanf ("%d", &num);
                        i = numLista(num);
                        
                        printf ("\nEntre com o novo valor: ");
                        scanf ("%d", &num2);
                        j = numLista(num2);
               
                        if(verificando(&tabelahash[j], num2) == 0){
                           printf("O valor novo já existe na tabela ou o valor antigo não existe!");
                           break;
                        }
               
                        if (i != j){
                           remover(&tabelahash[i], num);
                           inserir(&tabelahash[j], num2);
                           printf("Valor alterado com sucesso!");
                           break;
                           }
               
                        resp = alterar (tabelahash[i], num, num2);
                        if (resp == 1)
                        {
                           printf ("\n\tAlteração realizadas!");
                  }
                  else
                  {
                     printf ("\n\tNenhuma alteração foi feita!");
                  }
                  break;

            //Busca
            case 4: printf ("\nEntre com o valor a ser buscado: ");
                        scanf ("%d", &num);

                        i = num % 10;
                        //chamando a função
                        resp = buscar (tabelahash[i], num);

                  if (resp)
                        {
                           printf ("\n\tO valor %d foi encontrado na lista %d!", num, i);
                  }
                  else
                  {
                     printf ("\n\tO valor %d não foi encontrado em nenhuma lista!", num);
                  }
                  break;


            case 5: 
               printf("\nDigite Lista a ser exibida:");
               scanf("%d", &i);
               printf("\nExibindo Lista %d -> : ", i);
               exibir(tabelahash[i]);
            break;
                           
            case 6: printf ("\n\nSaindo...");
                                 break;
                                 default: printf ("\n\nOpção inválida! Tente novamente.");
            }
        }while (op != 6);
}

