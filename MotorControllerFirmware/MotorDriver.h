const uint8_t PIN_PWM = 3;
const uint8_t PIN_DIR_A = 4;
const uint8_t PIN_DIR_B = 5;

void driverSetup()
{
	pinMode(PIN_PWM, OUTPUT);
	pinMode(PIN_DIR_A, OUTPUT);
	pinMode(PIN_DIR_B, OUTPUT);
}

void driverSet(bool direction, uint8_t speed)
{
	digitalWrite(PIN_DIR_A, direction ? HIGH : LOW);
	digitalWrite(PIN_DIR_B, direction ? LOW : HIGH);
	analogWrite(PIN_PWM, speed);
}

void driverStop()
{
	digitalWrite(PIN_DIR_A, LOW);
	digitalWrite(PIN_DIR_B, LOW);
	digitalWrite(PIN_PWM, LOW);
}