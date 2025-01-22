#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

void print_crypto_details(json_t *item) {
    if (!item) {
        printf("Item is NULL\n");
        return;
    }
    const char *id = json_string_value(json_object_get(item, "id"));
    const char *symbol = json_string_value(json_object_get(item, "symbol"));
    double price = json_real_value(json_object_get(item, "current_price"));
    double high_24h = json_real_value(json_object_get(item, "high_24h"));
    double low_24h = json_real_value(json_object_get(item, "low_24h"));

    if (id && symbol && price && high_24h && low_24h) {
      printf("\nCryptocurrency: %s (%s)\n", id, symbol);
printf("  Current Price: %.2f $\n", price);
printf("  24h High: %.2f $\n", high_24h);
printf("  24h Low: %.2f $\n", low_24h);

    }
}

int main() {
    FILE *file = fopen("./data/crypto.json", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    json_error_t error;
    json_t *root = json_loadf(file, 0, &error);
    if (!root) {
        fprintf(stderr, "Error while loading the JSON: %s\n", error.text);
        fclose(file);
        return 1;
    }

    printf("JSON loaded successfully\n");

    // Fetch and print details for each cryptocurrency in the array
    for (size_t i = 0; i < json_array_size(root); i++) {
        json_t *item = json_array_get(root, i);
        if (item) {
            print_crypto_details(item);
        } else {
            printf("Error accessing item %zu in the array\n", i);
        }
    }

    fclose(file); // Close the file
    return 0;
}