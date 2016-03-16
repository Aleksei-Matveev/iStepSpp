#include <stdafx.h>

struct _tList {		// Структура для хранения данных 
	void *data;		// Указатель на данные
	_tList *back;	// Указатель на предыдущий элемент списка
	_tList *next;	// Указатель на следующий элемент списка
};

static struct _tHeadList {
	_tList *head = NULL;	// Указатель на начало списка _tList
	char *_tInfo = NULL;	// Информация о типе который хранится в _tList
	int count = 0;			// Количество элементов списка _tList
}_lHead;

#define _DELETE_DATA(PTR) (delete PTR)

_tList *_newElement(void *data);

_tList *_addElement(_tList *element, _tList *head);

_tList *_getElement(_tList *head, int count, const int pos = 0);

_tList *_deleteElement(_tList *head, int count, int pos);

/*
	Функция проверяет соответствие типов данных которые уже находятся в _tList с добавляемыми
*/
template <typename T> 
void *_newVElement(T element, char *_tElement) {
	return (strcmp(_tElement, typeid(element).name())) ? NULL : (new T(element));
}

/*
	Функция возвращает строку о типе данных
*/
template <typename T> const char *getTypeInfo(T element) {
	return typeid(element).name();
}

/*
	Функция инициализации структуры _tHeadList, записывает в поле _tInfo информацию о вводимом типе данных
	если заголовок уже существует проверяется соответствие типов
*/
template <typename T> int createHInfo(T element) {
	if (_lHead._tInfo) return strcmp(_lHead._tInfo, typeid(element).name());
	int _size = strlen(getTypeInfo(element)) + 1;
	_lHead._tInfo = new char[_size];
	return strcpy_s(_lHead._tInfo, _size, getTypeInfo(element));
}

/*
	Функция инициализирует структуру _tHeadList создает заголовок списка _tList
	если список уже существовал, то проверяет соответствие типов данных
*/
template <typename T> _tList *createHead(T element) {
	if (!createHInfo(element)) _lHead.head = _newElement(_newVElement(element, _lHead._tInfo));
	else return NULL;
	return _lHead.head;
}

/*
	Функция добавления нового элемента данных в список _tList
*/
template <typename T>
int add_Element(T element) {
	if (!_lHead.head) {										// Если заголовка не существовало - создаем
		if (createHead(element)) return ++_lHead.count;
		else return 0;
	}
	if (_addElement(_newElement(_newVElement(element, _lHead._tInfo)), _lHead.head)) return ++_lHead.count;
	else return 0;
}

/*
	Функция выборки произвольного элемента из списка _tList
*/
template <typename T>
T getElement(T &element, int pos) {
	_tList *_element = _getElement(_lHead.head, _lHead.count, pos);
	if (_element) {
		T *t = (T*)_element->data;
		if (t) {
			element = *t;
			return pos;
		}
	} 
	return 0;
}

/*
	Функция удаления произвольного элемента из списка _tList
*/
template <typename T>
int deleteElement(T *element, int pos) {
	_tList *_element = _deleteElement(_lHead.head, _lHead.count, pos);
	if (!_element) return -1;
	if (_element == _lHead.head) _lHead.head = _element->next;
	element = (T*)_element->data;
	_DELETE_DATA(element);
	_DELETE_DATA(_element);
	element = NULL;
	_lHead.count--;
	return pos;
}

/*
	Функция очистки всех элементов из списка _tList
	Очищает структуру _tHeadList после чего в список _tList можно будет добавлять другие типы данных
*/
template <typename T>
int clearElement(T *element) {
	int res = 0;
	for (int i = _lHead.count - 1; i > -1; i--) res = (i ^ deleteElement(element, i)) | res;
	delete[] _lHead._tInfo;
	return res;
}
