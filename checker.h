#include <stdio.h>

typedef enum {  false,
                true
}bool;
typedef struct {
    bool socFlag ;
    bool temperatureflag ;
    bool ChargeRateflag ;
    bool bms_Status ;
} BMS_parameters_s;

bool ChecktemperatureInRange(float temperature);
bool ChecksocInRange(float soc);
bool CheckchargeRateInRange(float chargeRate);
void finalcheck(bool bms_Status);
int batteryIsOk(float temperature, float soc, float chargeRate);

