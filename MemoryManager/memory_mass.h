
void __init(void *mass, int size_el);

void __init_compare_ptr(int (__cdecl **mass)(int*, int*), int size);

template <typename T> 
void *__calloc__(T t, int count) {
	return calloc(count, sizeof(T));
}

template <typename T>
T *__c_mass__(T t, int size) {
	return new T[size];
}
