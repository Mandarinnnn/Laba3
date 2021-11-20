#include <iostream>
#include <conio.h>

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
		storage = new Thing * [size];
	}

	void setObject(int i, Thing* newObject){
		if (i < size){
			storage[i] = newObject;
		}
		else {
			Thing** storage2 = new Thing * [i + 1];
			for (int j = 0; j < size; j++) {
				storage2[j] = storage[j];
			}
			for (int j = size; j < i; j++)
				storage2[j] = NULL;
			delete[] storage;
			storage = storage2;
			storage[i] = newObject;
			size = i+1;

		}
		//printf("setObject\n");
	}

	Thing& getObject(int i) {
		return *storage[i];
		printf("getObject\n");
	}

	int sizeStorage() {
		return size;
	}

	void getCount() {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (storage[i] != NULL) {
				counter = counter + 1;
			}
		}
		printf("Количество элементов: %d\nРазмер хранилища: %d\n", counter, size);
	}

	void deleteObject(int i) {
		/*if(storage[i] != NULL)
		storage[i] = NULL;*/
		storage[i] = NULL;
		/*printf("deleteObject\n");*/
	}

	void showNameObject(int i) {
		if (storage[i] != NULL) {
			storage[i]->showName();
		}
		else {
			printf("Пустой\n");
		}
	}

	void ShowNameStorage() {
		for (int i = 0; i < size; i++) {
			if (storage[i] != NULL) {
				storage[i]->showName();
			}
			else {
				printf("Пустой\n");
			}
		}
	}


};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	MyStorage storage(10);
	for (int i = 0; i < storage.sizeStorage(); i++) {
		storage.setObject(i, new Car());
	}
	/*for (int i = 0; i < storage.sizeStorage(); i++) {
		storage.getObject(i).ShowName();
	}
	storage.ShowNameStorage();
	printf("\n\n");
	storage.setObject(18, new Table());
	storage.setObject(23, new Table());
	storage.ShowNameStorage();
	printf("\n\n");
	storage.deleteObject(4);
	storage.ShowNameStorage();

	printf("\n\n");
	storage.deleteObject(4);
	storage.ShowNameStorage();*/
	unsigned int start_time = clock();
	printf("\n\n");
	for (int i = 0; i < 100; i++) {
		int a = rand() % 3;
		int b = rand()%storage.sizeStorage();
		int c;
		switch (a) {
		case 0:
			c = rand() % 2;
			if (c == 0) {
				storage.setObject(b, new Table);
				printf("setObject\n");
			}
			else {
				storage.setObject(b, new Car);
				printf("setObject\n");
			}
		case 1:
			storage.deleteObject(b);
			printf("deleteObject\n");
		case 2:
			storage.showNameObject(b);
			/*printf("ShowName\n");*/
		}
	}
	unsigned int end_time = clock(); 
	unsigned int search_time = end_time - start_time;
	printf("\n%d\n", search_time);
	storage.getCount();
	/*storage.ShowNameStorage();*/



}