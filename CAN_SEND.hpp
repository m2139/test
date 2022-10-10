#ifndef CAN_SEND_H
#define CAN_SEND_H
#include "mbed.h"

#if 0
----------------------------------------------------------------------------------------------------------
~ピン配列~
F446RE D4 D10
L432KC D10 D2

~使用方法~
•送る側
CANSend can(RD,TD);
can.SEND(id,num1,num2,num3,num4);//id,numは自由に指定自由、値は４個まで行けますidは必須numは設定しなくてもいい

•受信側
CAN can(RD,TD);
CANMessage msg;//CANメッセージ生成
while(1){
    can3.read(msg);
    if(msg.id == 1) {//msg.idで送信側のidを参照することif文で値を振り分けれます
        num1 = (msg.data[0] * 16 * 16) + msg.data[1]; //これらの式で送られてきた値を戻す。
        num2 = (msg.data[2] * 16 * 16) + msg.data[3]; //いじり方次第では値の数を増やせる(値の上限値は小さくなる)
        num3 = (msg.data[4] * 16 * 16) + msg.data[5]; //わからないことがあればM2139までお問い合わせください
        num4 = (msg.data[6] * 16 * 16) + msg.data[7]; //  2022年10月10日   13:00  (月)　制作
    }
}
----------------------------------------------------------------------------------------------------------
#endif

class CANSend
{

public:
    CANSend(PinName RD,PinName TD);
    void SEND(int,int num1 = 0,int num2 = 0,int num3 = 0 ,int num4 = 0);//id data
private:
    CAN can;//can通信宣言
    char DATA[8];
};
#endif