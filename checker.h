#include <stdio.h>

typedef enum {  false,
                true
}bool;

bool ChecktemperatureInRange(float temperature);
bool ChecksocInRange(float soc);
int finalcheck();
bool CheckchargeRateInRange(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

