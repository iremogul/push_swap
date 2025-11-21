#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // printf için (Sadece testte kullanıyoruz, projede yasak olabilir)

// Stack'i yazdırmak için yardımcı fonksiyon (Sadece test amaçlı)
void print_stack(t_stack *stack, char *stack_name)
{
    t_node *current;

    printf("\n--- %s ---\n", stack_name);
    if (!stack || !stack->top)
    {
        printf("(Empty)\n");
        return;
    }
    current = stack->top;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("--------------\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;

    // 1. Argüman kontrolü
    if (argc < 2)
        return (0);

    // 2. Stack A'yı başlat
    stack_a = stack_new();
    if (!stack_a)
        return (1);

    // 3. Girdileri işle ve Stack A'yı doldur
    // parse_input_and_fill başarılı olursa 1, hata olursa 0 döner.
    if (!parse_input_and_fill(argc, argv, stack_a))
    {
        // Hata durumunda stack'i temizle ve çık (Error mesajı zaten fonksiyon içinde yazılıyor)
        stack_free(stack_a);
        return (1);
    }

    // 4. Sonucu gör: Stack A'yı yazdır
    print_stack(stack_a, "Stack A");

    // 5. Temizlik: Stack'i boşalt ve programdan çık
    stack_free(stack_a);
    return (0);
}