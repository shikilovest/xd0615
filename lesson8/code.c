/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/

int inches = 0;//定义变量inches并初始化为0

int cm = 0;//定义变量cm并初始化为0

long readUltrasonicDistance(int triggerPin, int echoPin)//设置读取超声波距离的函数
{
  pinMode(triggerPin, OUTPUT);  // 将触发引脚端设为输出

  digitalWrite(triggerPin, LOW);//将触发引脚设为低电平
  delayMicroseconds(2);//将触发引脚设置为低电平状态持续2微秒
  digitalWrite(triggerPin, HIGH);//将触发引脚设为高电平
  delayMicroseconds(10);//将触发引脚设置为高电平状态持续10微秒
  digitalWrite(triggerPin, LOW);//将触发引脚设为低电平
  pinMode(echoPin, INPUT);//将回波引脚设为输入
  return pulseIn(echoPin, HIGH);//读取回波引脚，并返回声波传播时间（以微秒为单位）

}

void setup()
{
  Serial.begin(9600);//串口初始化

}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7);//以厘米为单位测量ping时间
  inches = (cm / 2.54);//除以2.54转换为英寸
  Serial.print(inches);//串口输出英寸的值
  Serial.print("in, ");//串口输出字符串"in,"
  Serial.print(cm);//串口输出变量cm的值
  Serial.println("cm");//串口输出字符串"cm"
  delay(100); // 等待100毫秒
}