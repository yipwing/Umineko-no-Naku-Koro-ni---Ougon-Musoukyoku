#pragma once

struct key_entry_t {
	const char *	name;
	unsigned int	address;
	unsigned int	orig_address;
	unsigned int	key;
};

struct key_entry_t key_table[] = {
	{ "KeyUp",	0x59F9,		0x59F9,		DIK_UP		},
	{ "KeyDown",	0x5A0A,		0x5A0A,		DIK_DOWN	},
	{ "KeyLeft",	0x5A1B,		0x5A1B,		DIK_LEFT	},
	{ "KeyRight",	0x5A2C,		0x5A2C,		DIK_RIGHT	},
	{ "KeyA",	0x5A3D,		0x5A3D,		DIK_Z		},
	{ "KeyB",	0x5A4E,		0x5A4E,		DIK_X		},
	{ "KeyC",	0x5A5F,		0x5A5F,		DIK_C		},
	{ "KeyTouch",	0x5A70,		0x5A70,		DIK_S		},
	{ "KeyAppeal",	0x5A81,		0x5A81,		DIK_LSHIFT	},
	{ "KeyUnknown1",0x5A8F,		0x5A8F,		DIK_A		},
	{ "KeyUnknown2",0x5AA0,		0x5AA0,		DIK_D		},
	{ "KeyUnknown3",0x5AB1,		0x5AB1,		DIK_Q		},
	{ "KeyUnknown4",0x5AC2,		0x5AC2,		DIK_E		},
	{ "KeyStart",	0x5AD3,		0x5AD3,		DIK_W		},
	{ "KeyUnknown5",0x5AE4,		0x5AE4,		DIK_RETURN	},
	{ "KeyUnknown6",0x88043,	0x5AF5,		DIK_RSHIFT	},
	{ "KeyAB",	0x87FE3,	0x0,		0		},
	{ "KeyBC",	0x88003,	0x0,		0		},
	{ "KeyABC",	0x88018,	0x0,		0		},
};

const unsigned char code_1[7] = {
   0xE9,  0xE9,  0x24,  0x08,  0x00,  0x90,  0x90,
};

const unsigned int code_1_size = sizeof(code_1);
const unsigned int code_1_address = 0x5AF3;

const unsigned char code_2[] = {
	// RETN (original)
	0xc3,

	// CMP BYTE PTR SS:[EBP+xx], 0
	0x80, 0xBD, 0x00, 0x00, 0x00, 0x00, 0x00,
	// JE SHORT blahblah ������
	0x74, 0x17,
	// JMP SHORT blah blah  ��������..
	0xeb, 0x09,

	// original crap    ԭʼ����..������..
	0xcc, 0xcc, 0xcc, 0xcc,
	0xE9,  0xDB,  0xF1,  0xF7,  0xFF,   // JMP blah blah  ������..

	// OR DWORD PTR SS:[ESP+14], 20 (AB)    AB��ϼ�...
	0x83, 0x4c, 0x24, 0x14, 0x20,
	// JMP SHORT blahblah
	0xeb, 0x05,

	// original ԭʼ������
	0xcc, 0xcc, 0xcc, 0xcc,
	0xc3, // RETN

	// again, BC (0x40) ��,�������ϼ�BC
	0x80, 0xBD, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x74, 0x0c,
	0xeb, 0x05,
	0xcc, 0xcc, 0xcc, 0xcc, 0xc3, // (orig)  ���������ԭʼ������..
	// bc�ļ���
	0x83, 0x4c, 0x24, 0x14, 0x40,
    // ���ﻹ��ABC��ϼ�..
    0x80, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xeb, 0x18,

	// orig stuff ԭʼ...��ɶ..
	0xcc,
	0x68, 0xC0, 0xB5, 0x44, 0x00,
	0x68, 0x10, 0x27, 0x00, 0x00,
	0x6a, 0x1c,
	0x68, 0xA0, 0x38, 0x4B, 0x00,
	0xe8, 0xf6, 0x33, 0xfd, 0xff,
	0xc3,

    //abc continue  ���ż���ABC
    0x74, 0x08,
    0x81, 0x4c, 0x24, 0x14, 0x80, 0x00, 0x00, 0x00,

    // CMP BYTE PTR SS:[EBP+75A], 0  ��������һ����λ,�����Ǹ�RSHIFT
	0x80, 0xbd, 0x5a, 0x07, 0x00, 0x00, 0x00,
	// JMP xxxxxx // ���ظĹ��ĵ�ַ
	0xE9,  0xAD,  0xDA,  0xF7,  0xFF,
};

const unsigned int code_2_size = sizeof(code_2);
const unsigned int code_2_address = 0x87FE0;	// 466170 // 487BB0 //486FB0 //487340 // 88500

int key_table_size = sizeof(key_table)/sizeof(key_table[0]);