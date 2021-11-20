#include <iostream>
#include <conio.h>

using namespace std;

class Thing {
public: 
	virtual void ShowName() {
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

	void ShowName() {
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

	void ShowName() {
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
		if (i <= size){
			storage[i] = newObject;
		}
		else {
			Thing** storage2=new Thing* [i];
			for (int j = 0; j < size; j++) {
				storage2[j] = storage[j];
			}
			for (int j = 0; j < size; j++) {
				delete storage[j];
			}
			delete storage;
			storage = storage2;
			storage[size] = newObject;
			size = i;
		}
	}

	Thing& getObject(int i) {
		return *storage[i];
	}

	int getCount() {
		return size;
	}

	void deleteObject(int i) {
		storage[i] = NULL;
	}

};

int main()
{
	MyStorage storage(10);
	for (int i = 0; i < storage.getCount(); i++) {
		storage.setObject(i, new Table());
	}
	for (int i = 0; i < storage.getCount(); i++) {
		storage.getObject(i).ShowName();
	}

}