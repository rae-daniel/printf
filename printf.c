#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count;
    char_count=0; 
    while (*format != '\0') {
        if (*format == '%') {
            format++; 
            switch (*format) {
                case 'c':
                    char_count += putchar(va_arg(args, int));
                    break;
                case 's':
                    char_count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    char_count += putchar('%');
                    break;
                default:
                    putchar('%'); 
                    char_count++;
                    break;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

int  main() {
    int count = _printf("Hello, %c world! This is a %s example. %%\n", 'C', "printf");
    printf("\nTotal characters printed: %d\n", count);
    return 0;
}
