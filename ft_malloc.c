#include "malloc.h"

/*
A função malloc() aloca dinamicamente memória na área conhecida como heap. Internamente, a função malloc() realiza as seguintes etapas:

    1) Verificação do tamanho solicitado: A função malloc() recebe um argumento que especifica o número de bytes de memória que 
    devem ser alocados. Ela verifica se esse valor é válido e maior que zero.

    2) Pesquisa de bloco de memória livre: A função malloc() pesquisa na lista de blocos de memória livre na heap para encontrar
    um bloco que seja grande o suficiente para alocar a quantidade solicitada de memória. Essa lista é mantida internamente 
    pela biblioteca e registra os blocos de memória que foram liberados e estão disponíveis para reuso.

                Lista encadeada: Uma abordagem comum é usar uma lista encadeada, em que cada nó da lista representa 
            um bloco de memória livre e contém informações sobre o tamanho do bloco e um ponteiro para o próximo 
            nó da lista. Durante a pesquisa, a função malloc() percorre a lista até encontrar um bloco que seja 
            grande o suficiente para alocar a memória solicitada. Esse bloco é então marcado como alocado e removido 
            da lista.

                Algoritmo First Fit: Outra abordagem é o uso do algoritmo First Fit (primeiro encaixe), que percorre a 
            lista de blocos de memória livre e seleciona o primeiro bloco que seja grande o suficiente para alocar a 
            memória solicitada. Essa abordagem é mais rápida, pois evita percorrer toda a lista, mas pode resultar em 
            fragmentação da memória ao longo do tempo.

                Algoritmo Best Fit: O algoritmo Best Fit (melhor encaixe) é semelhante ao First Fit, mas em vez de selecionar
            o primeiro bloco que seja grande o suficiente, ele procura o bloco que seja o mais próximo do tamanho necessário.
            Essa abordagem ajuda a reduzir a fragmentação da memória, mas pode ser mais lenta do que o First Fit, pois requer
            uma pesquisa mais detalhada.

    3) Alocação do bloco de memória: Uma vez que um bloco de memória adequado é encontrado, ele é marcado como alocado e removido
    da lista de blocos livres. O endereço desse bloco é retornado como resultado da função malloc().

    4) Gerenciamento de metadados: A função malloc() também realiza o gerenciamento interno de metadados, que são informações 
    adicionais armazenadas junto com o bloco de memória alocado. Esses metadados podem incluir informações como o tamanho 
    do bloco alocado, informações de controle internas e outros detalhes necessários para o correto funcionamento da biblioteca.

    5) Retorno do endereço alocado: Após a alocação bem-sucedida, a função malloc() retorna o endereço do bloco de memória 
    alocado. Esse endereço é atribuído a um ponteiro na sua aplicação, permitindo que você acesse e manipule a memória alocada.

*/

Block* head = NULL;
 
void    *ft_malloc(size_t size)
{
    if (size == 0)
        return NULL;   
    
    Block* current = head;
    Block* prev =  NULL;
    void* memory = NULL;

    while (current != NULL)
    {
        if (current -> free && current -> size >= size)
        {
            current -> free = 0;
            return (void*)(current +1);
        }
        prev = current;
        current = current -> NEXT;
    }

    size_t chunkSize = size + BLOCK_SIZE;
    if (chunkSize < DEFAULT_CHUNK_SIZE)
        chunkSize = DEFAULT_CHUNK_SIZE;
    memory = sbrk(chunkSize);

    if (memory == (void*)-1)
        return NULL;

    current = (Block*)memory;
    current -> size = chunkSize - BLOCK_SIZE;
    current -> NEXT = NULL;
    current -> free = 0;

    if (prev != NULL)
        prev -> NEXT = current;

    if (head == NULL)
        head = current;
    
    return (void*)(current + 1);
}


// void ft_free(void* ptr)
// {
//     if (ptr == NULL)
//         return;
//     BLOCK* current = (BLOCK*)ptr -1;
//     current -> free = 1;
// }

int main(void)
{
    int* num = (int*)ft_malloc(sizeof(int));
    if (num != NULL)
    {
        *num = 42;
        printf("numero %d", *num);
        free(num);
    }
    return 0;
}