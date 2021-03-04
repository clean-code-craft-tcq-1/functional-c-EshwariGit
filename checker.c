#include <stdio.h>
#include <assert.h>
#include "checker.h"


IsBatteryStatusInRange TemparatureValue = {
        0.0,
        45.0,
        "Temparature"
};
IsBatteryStatusInRange SocValue = {
        20.0,
        80.0,
        "StateOfCharge"
};
IsBatteryStatusInRange ChargeRateValue = {
        0.0,
        0.8,
        "ChargeRate"
};


int ChecktemperatureInRange(float temperature, float soc, float chargeRate) {

    int istemperatureinrange = BATTERY_CONDITION_GOOD;
    int issocinrange = BATTERY_CONDITION_GOOD;
    int ischargerateinrange = BATTERY_CONDITION_GOOD;
        
    if (temperature<TemparatureValue.BatteryL|| temperature>TemparatureValue.BatteryU)
    {
        istemperatureinrange = BATTERY_CONDITION_BAD;
    }
      
    if(soc<SocValue.BatteryL || soc>SocValue.BatteryU )
    {
        issocinrange = BATTERY_CONDITION_BAD;
    }
        
    if(chargeRate<ChargeRateValue.BatteryL || chargeRate>ChargeRateValue.BatteryU )
    {
        ischargerateinrange = BATTERY_CONDITION_BAD;
    }
    PrintBatterycondition(TemparatureValue,istemperatureinrange );
    PrintBatterycondition(SocValue,issocinrange);
    PrintBatterycondition(ChargeRateValue,ischargerateinrange );
   return (istemperatureinrange && issocinrange && ischargerateinrange);
        
}

void PrintBatterycondition(IsBatteryStatusInRange BatteryData_Type, int BatteryMessageI)
{
    printf("%s %s \n", BatteryData_Type.BatteryD, BatteryMessage[BatteryMessageI]);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int istemperatureinrange, issocinrange, ischargerateinrange;
    istemperatureinrange = ChecktemperatureInRange(temperature);
    issocinrange = ChecktemperatureInRange(soc);
    ischargerateinrange = ChecktemperatureInRange(chargeRate);
    return ( istemperatureinrange && issocinrange && ischargerateinrange);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
