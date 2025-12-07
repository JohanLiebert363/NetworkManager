#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ssid[100];
    char password[100];

    printf("WiFi SSID: ");
    scanf("%99s", ssid);

    printf("WiFi Password: ");
    scanf("%99s", password);

    // Connect using iwctl
    char wifi_cmd[256];
    sprintf(wifi_cmd, "iwctl station wlan0 connect '%s' --passphrase '%s'", ssid, password);

    printf("Connecting (iwd)...\n");
    int result = system(wifi_cmd);

    if (result != 0) {
        printf("❌ WiFi connection failed.\n");
    } else {
        printf("✔ Connected.\n");
    }

    return 0;
}
