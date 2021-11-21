#include <iostream>
#include <ctime>
using namespace std;

class Thing {
public: 
	virtual void showName() {
		printf("Thing\n");
	}
	virtual~Thing() {
	}
};

class Table : public Thing{
private:
	int x;
	int y;
public:
	Table() {
		x = 0;
		y = 0;
	}

	Table(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Table(const Table& t) {
		x = t.x;
		y = t.y;
	}

	void showName() {
		printf("Table\n");
	}
	~Table() {
	}
};

class Car : public Thing {
private:
	int x;
	int y;
	int color;
public:
	Car() {
		x = 0;
		y = 0;
		color = 0;
	}

	Car(int x, int y, int color) {
		this->x = x;
		this->y = y;
		this->color = color;
	}

	Car(const Car& c) {
		x = c.x;
		y = c.y;
		color = c.color;
	}
	~Car() {
	}

	void showName() {
		printf("Car\n");
	}
};

class MyStorage {
private:
	int size;
	Thing** storage;
public:

	MyStorage(int i) {
		size = i;
		storage = new Thing *[size];
	}

	void setObject(int i, Thing* newObject){
		storage[i] = newObject;
	}

	void addObject(Thing* newObject) {
		Thing** storage2 = new Thing * [size + 1];
		if (size != 0) {
			for (int j = 0; j < size; j++) {
				storage2[j] = storage[j];
			}
		}
		delete[] storage;
		storage = storage2;
		storage[size] = newObject;
		size = size + 1;
	}


	Thing& getObject(int i) {
		return *storage[i];
	}

	int getCount() {
		return size;
	}

	void removeObject(int i) {
		if (size !=1) {
			Thing** storage2 = new Thing * [size - 1];
			for (int j = 0; j < i; j++) {
				storage2[j] = storage[j];
			}
			for (int j = i; j < size - 1; j++) {
				storage2[j] = storage[j + 1];
			}
			delete[] storage;
			size = size - 1;
			storage = storage2;
		}
	}

	void deleteObject(int i) {
		storage[i] = nullptr;
	}

	void showNameObject(int i) {
		if(size!=0)
		storage[i]->showName();
	}

	void showNameStorage() {
		for (int i = 0; i < size; i++) {
			storage[i]->showName();
		}
	}
	~MyStorage() {
		for (int i = 0; i < size; i++) {
			delete storage[i];
		}
		delete[] storage;
	}
};

void cycle(MyStorage& storage, int max) {
	unsigned int s = clock();
	printf("\n\n");
	for (int i = 0; i < max; i++) {
		int a = rand() % 3;
		int b = rand() % storage.getCount();
		int k = rand() % 2;
		switch (a) {
		case 0:
			if (k==0)
			storage.addObject(new Table);
			else 
				storage.addObject(new Table);

			printf("addObject\n");
			break;
		case 1:
			storage.removeObject(b);
			printf("removeObject\n");
			break;
		case 2:
			storage.showNameObject(b);
			break;
		}
	}
	unsigned int e = clock();
	unsigned int time = e - s;
	printf("\nВремя: %d миллисекунд\n", time);
	printf("Количество объектов: %d\n", storage.getCount());
}

int main()
{

	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	MyStorage storage(10);
	for (int i = 0; i < storage.getCount(); i++) {
		int a = rand() % 2;
		if (a == 0) { 
			storage.setObject(i, new Car());
		}
		else {
			storage.setObject(i, new Table());
		}
	}


	storage.showNameStorage();
	printf("\nКоличество объектов: %d\n", storage.getCount());

	cycle(storage, 100);
	printf("\n\n");
	system("pause");
	cycle(storage, 1000);
	printf("\n\n");
	system("pause");
	cycle(storage, 10000);
}