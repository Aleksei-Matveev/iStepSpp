#include <stdafx.h>

struct _tList {		// ��������� ��� �������� ������ 
	void *data;		// ��������� �� ������
	_tList *back;	// ��������� �� ���������� ������� ������
	_tList *next;	// ��������� �� ��������� ������� ������
};

static struct _tHeadList {
	_tList *head = NULL;	// ��������� �� ������ ������ _tList
	char *_tInfo = NULL;	// ���������� � ���� ������� �������� � _tList
	int count = 0;			// ���������� ��������� ������ _tList
}_lHead;

#define _DELETE_DATA(PTR) (delete PTR)

_tList *_newElement(void *data);

_tList *_addElement(_tList *element, _tList *head);

_tList *_getElement(_tList *head, int count, const int pos = 0);

_tList *_deleteElement(_tList *head, int count, int pos);

/*
	������� ��������� ������������ ����� ������ ������� ��� ��������� � _tList � ������������
*/
template <typename T> 
void *_newVElement(T element, char *_tElement) {
	return (strcmp(_tElement, typeid(element).name())) ? NULL : (new T(element));
}

/*
	������� ���������� ������ � ���� ������
*/
template <typename T> const char *getTypeInfo(T element) {
	return typeid(element).name();
}

/*
	������� ������������� ��������� _tHeadList, ���������� � ���� _tInfo ���������� � �������� ���� ������
	���� ��������� ��� ���������� ����������� ������������ �����
*/
template <typename T> int createHInfo(T element) {
	if (_lHead._tInfo) return strcmp(_lHead._tInfo, typeid(element).name());
	int _size = strlen(getTypeInfo(element)) + 1;
	_lHead._tInfo = new char[_size];
	return strcpy_s(_lHead._tInfo, _size, getTypeInfo(element));
}

/*
	������� �������������� ��������� _tHeadList ������� ��������� ������ _tList
	���� ������ ��� �����������, �� ��������� ������������ ����� ������
*/
template <typename T> _tList *createHead(T element) {
	if (!createHInfo(element)) _lHead.head = _newElement(_newVElement(element, _lHead._tInfo));
	else return NULL;
	return _lHead.head;
}

/*
	������� ���������� ������ �������� ������ � ������ _tList
*/
template <typename T>
int add_Element(T element) {
	if (!_lHead.head) {										// ���� ��������� �� ������������ - �������
		if (createHead(element)) return ++_lHead.count;
		else return 0;
	}
	if (_addElement(_newElement(_newVElement(element, _lHead._tInfo)), _lHead.head)) return ++_lHead.count;
	else return 0;
}

/*
	������� ������� ������������� �������� �� ������ _tList
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
	������� �������� ������������� �������� �� ������ _tList
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
	������� ������� ���� ��������� �� ������ _tList
	������� ��������� _tHeadList ����� ���� � ������ _tList ����� ����� ��������� ������ ���� ������
*/
template <typename T>
int clearElement(T *element) {
	int res = 0;
	for (int i = _lHead.count - 1; i > -1; i--) res = (i ^ deleteElement(element, i)) | res;
	delete[] _lHead._tInfo;
	return res;
}
