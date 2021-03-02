#include <stdio.h>

typedef enum {  false,
                true
}bool;
typedef struct {
    bool socFlag ;
    bool temperatureflag ;
    bool ChargeRateflag ;
    bool bms_Status ;
} BMS_req;

bool ChecktemperatureInRange(float temperature);
bool ChecksocInRange(float soc);
bool CheckchargeRateInRange(float chargeRate);
void finalcheck(bool bms_Status1);
int batteryIsOk(float temperature, float soc, float chargeRate);

