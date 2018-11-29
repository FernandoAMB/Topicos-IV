#define Memory_Base_Address (int *) 0x0000
#define ACC_Address (int *) 0x3010
#define ClockCounter_Address (int *) 0x3014

#define FOR_LENGTH 10

#define resetClockCounter() *((int *) 0x3014) = 0;
#define pauseClockCounter() *((int *) 0x3014) = 1; // pause / unpause
#define getClockCounterCount() (*((int *) 0x3014))

int i;
int *pointer = Memory_Base_Address;

int main()
{
	int countACC = 0, countFor = 0;
	resetClockCounter();
	pauseClockCounter(); //unpause
	for (i = 0; i < FOR_LENGTH; i++)
	{
		*ACC_Address = pointer[i];
	}
	pauseClockCounter();
	countACC = getClockCounterCount();

	int temp = 0;
	resetClockCounter();
	pauseClockCounter(); //unpause
	for (i = 0; i < FOR_LENGTH; i++) {
		temp = temp + pointer[i];
	}
	pauseClockCounter();
	countFor = getClockCounterCount();

	*( Memory_Base_Address + 11) = countACC;
	*( Memory_Base_Address + 15) = countFor;

	return 0;
}
