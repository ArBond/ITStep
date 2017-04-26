#include <stdio.h>
#include <string.h>
 
struct Header
{
    int RecordCount;
    int CurrencyCount;
    int Data;
    int CurrencyCount2;
    int Data2;
};
 
struct CurrencyRates
{
    float BynToUsd;
    float UsdToByn;
    float BynToEur;
    float EurToByn;
    char BankName[256];
};
 
#define FILE_NAME "db.bin"
 
int main()
{
    char headerData[200];
 
 
    struct Header header;
    header.RecordCount = 2;
    header.CurrencyCount2 = 5;
    header.Data2 = 67;
 
    if (sizeof(struct Header) > sizeof(headerData))
    {
        printf("Error!");
        return -1;
    }
 
    memcpy(headerData, &header, 200);
 
    struct CurrencyRates currency;
    FILE* rates = fopen(FILE_NAME, "rb");
 
    if (rates == NULL)
    {
        rates = fopen(FILE_NAME, "wb");
       
        printf("BYN to USD: ");
        scanf("%f", &currency.BynToUsd);
        printf("\nUSD to BYN: ");
        scanf("%f", &currency.UsdToByn);
        printf("\nBYN to EUR: ");
        scanf("%f", &currency.BynToEur);
        printf("\nEUR to BYN: ");
        scanf("%f", &currency.EurToByn);
        strcpy(currency.BankName, "hello");
 
        fwrite(&headerData, sizeof(headerData),
            1, rates);
        fwrite(&currency, sizeof(struct CurrencyRates),
            1, rates);
        fwrite(&currency, sizeof(struct CurrencyRates),
            1, rates);
 
        fclose(rates);
        return 0;
    }
 
    fread(&header, sizeof(struct Header),
        1, rates);
    fseek(rates, 200, SEEK_SET);
    fread(&currency, sizeof(struct CurrencyRates),
        1, rates);
    printf("Records: %i\n\n", header.RecordCount);
    printf("\nBYN to USD: %.4f\n", currency.BynToUsd);
    printf("USD to BYN: %.4f\n", currency.UsdToByn);
    printf("BYN to EUR: %.4f\n", currency.BynToEur);
    printf("EUR to BYN: %.4f\n", currency.EurToByn);
 
    fread(&currency, sizeof(struct CurrencyRates),
        1, rates);
    printf("\nBYN to USD: %.4f\n", currency.BynToUsd);
    printf("USD to BYN: %.4f\n", currency.UsdToByn);
    printf("BYN to EUR: %.4f\n", currency.BynToEur);
    printf("EUR to BYN: %.4f\n", currency.EurToByn);
 
    fseek(rates, 0, SEEK_END);
    int const fileSize = ftell(rates);
 
    if ((header.RecordCount * sizeof(struct CurrencyRates) +
        sizeof(headerData)) == fileSize)
    {
        printf("Bank: %s\n", currency.BankName);
    }
    else
    {
        printf("Bank: -\n");
    }
 
    fclose(rates);
    return 0;
}
