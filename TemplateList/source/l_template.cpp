#include <stdafx.h>

static _tList *ptr = NULL;
static int _pos = 0;

#define _NEXT_PTR() ((ptr->next) ? ptr = ptr->next : ptr)
#define _BACK_PTR() ((ptr->back) ? ptr = ptr->back : ptr)
#define _NEXT_POS(pos) ((_pos != pos) ? ++_pos : 0)
#define _BACK_POS(pos) ((_pos != pos) ? --_pos : 0)

inline void _paste(_tList *A, _tList *B);

_tList *_search(int pos, const int mode = 0);

_tList *_addElement(_tList *element, _tList *head) {
	if (!element) return NULL;
	static _tList *_element = head;
	_paste(_element, element);
	return _element = element;
}

_tList *_getElement(_tList *head, int count, const int pos) {
	if (!ptr) ptr = head;
	if (pos < count) {
		if (_pos) {
			if (_pos > pos) {
				if (pos - _pos <= pos)
					return _search(pos, 1);
				else {
					_pos = 0;
					ptr = head;
					return _search(pos);
				}
			}
			else return _search(pos);
		}
		else return _search(pos);
	}
	else return NULL;
}

_tList *_deleteElement(_tList *head, int count, int pos) {
	_tList *_element = _getElement(head, count, pos);
	if (!_element) return NULL;
	_paste(_element->back, _element->next);
	_BACK_POS(pos - 1);
	_BACK_PTR();
	return _element;
}

_tList *_newElement(void *data) {
	if (!data) return NULL;
	_tList *_new = new _tList;
	_new->back = _new->next = NULL;
	_new->data = data;
	return _new;
}

inline void _paste(_tList *A, _tList *B) {
	if (A) A->next = B;
	if (B) B->back = A;
}

_tList *_search(int pos, const int mode) {
	switch (mode)
	{
	case (0) : {
		while (_NEXT_POS(pos)) _NEXT_PTR();
		break;
	}
	case (1) : {
		while (_BACK_POS(pos)) _BACK_PTR();
		break;
	}
	default:
		return NULL;
		break;
	}
	return ptr;
}
