#include <stdio.h>
#include <assert.h>
#include "checker.h"


static bms_StatusParam BMS_parameters_s = {
        false,
        false,
        false,
        false
}

bool ChecktemperatureInRange(float temperature) {

bool tempflag = false;
    if(temperature < 0 || temperature > 45)
    {
        tempflag = true;
        printf("Temperature out of range!\n");
        finalcheck(true);
    }
    return tempflag;
}

bool ChecksocInRange(float soc){

bool socflag1 = false;
    if(soc < 20 || soc > 80) {
        {
            socFlag1 = true;
            printf("soc out of range!\n");
            finalcheck(true);
        }
        return socFlag1;
    }
}

    bool CheckchargeRateInRange(float chargeRate){
bool ChargeRateflag1 = false;

        if(chargeRate > 0.8)
        {
            ChargeRateflag1 = true;
            printf("chargerate out of range!\n");
            finalcheck(true);
        }
        return ChargeRateflag1;

    }

void finalcheck(bool bms_Status1){

    BMS_parameters_s.bms_Status = true;

}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    BMS_parameters_s.socFlag = ChecksocInRange(soc);
    BMS_parameters_s.temperatureflag =ChecktemperatureInRange(temperature);
    BMS_parameters_s.ChargeRateflag = CheckchargeRateInRange(chargeRate);

    if( true == BMS_parameters_s.bms_Status)
     {
         return 0;
     }
     else
     {
         return 1;
     }
    }

    int main() {
        assert(batteryIsOk(25, 70, 0.7));
        assert(!batteryIsOk(50, 85, 0));
    }
