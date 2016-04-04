// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#define BUFF_COUNT 0x01000000

#define _USE_OMP 1	// ������� ���� ��������� ���� - ��� 1 ��������������� ���������

enum E_SIMPLE {
	zero = 0x00000001,
	positive = 0x00000002,
	negative = 0x00000004,
	odd = 0x00000008,
	even = 0x00000010
};

#include "targetver.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <tchar.h>
#include <omp.h>

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������

#include "memory_mass.h"
