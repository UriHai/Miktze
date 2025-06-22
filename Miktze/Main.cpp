
#include <memory>
int main() {
	int* a = new int[4];
	free((void*)1000);

	return 0;
}