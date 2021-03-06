#pragma once

unsigned char version1[] = {
	0x43, 0x52, 0x4F, 0x53, 0x53
};
unsigned char version2[] = {
	0x43, 0x72, 0x6F, 0x73, 0x73,
};

const unsigned char combocode[] =
{
	0xC3, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xE9,
};

const unsigned char code1[] =
{
    0x80, 0xBD, 0xEC, 0x07, 0x00, 0x00, 0x00,
};

const unsigned char code2[] = {
	0x80, 0xBD, 0xF4, 0x07, 0x00, 0x00, 0x00,
};

const unsigned char code3[] = {
	0x80, 0xBD, 0xEF, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code4[] = {
	0x80, 0xBD, 0xF1, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code5[] = {
	0x80, 0xBD, 0x50, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code6[] = {
	0x80, 0xBD, 0x51, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code7[] = {
	0x80, 0xBD, 0x52, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code8[] = {
	0x80, 0xBD, 0x43, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code9[] = {
	0x80, 0xBD, 0x4E, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code10[] = {
	0x80, 0xBD, 0x42, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code11[]={
	0x80, 0xBD, 0x44, 0x07, 0x00, 0x00, 0x00,
};

const unsigned char code12[] = {
	0x80, 0xBD, 0x34, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code13[] = {
	0x80, 0xBD, 0x36, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code14[] = {
	0x80, 0xBD, 0x35, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code15[] = {
	0x80, 0xBD, 0x40, 0x07, 0x00, 0x00, 0x00
};

const unsigned char code16[] = {
	0x80, 0xBD, 0x5A, 0x07, 0x00, 0x00, 0x00
};

/*
unsigned int tolendian(unsigned int bigendian)
{
	byte* p = (byte*)&bigendian;
	return (p[0]<<24)+(p[1]<<16)+(p[2]<<8)+p[3];
}
*/


bool isPEfile(LPVOID ImageBase)
{
	PIMAGE_DOS_HEADER pDH = NULL;
	PIMAGE_NT_HEADERS pNtH = NULL;

	if(!ImageBase)
		return false;

	pDH=(PIMAGE_DOS_HEADER)ImageBase;
	if(pDH->e_magic!=IMAGE_DOS_SIGNATURE)
		return false;

	pNtH=(PIMAGE_NT_HEADERS32)((DWORD)pDH+pDH->e_lfanew);
	if(pNtH->Signature!=IMAGE_NT_SIGNATURE)
		return false;

	return true;
}

PIMAGE_NT_HEADERS GetNtHeaders(LPVOID ImageBase)
{
	if(!isPEfile(ImageBase))
		return NULL;
	PIMAGE_NT_HEADERS pNtH;
	PIMAGE_DOS_HEADER pDH;

	pDH = (PIMAGE_DOS_HEADER)ImageBase;
	pNtH = (PIMAGE_NT_HEADERS)((DWORD)pDH + pDH->e_lfanew);

	return pNtH;
}

PIMAGE_FILE_HEADER GetFileHeader(LPVOID ImageBase)
{
	PIMAGE_NT_HEADERS pNtH = NULL;
	PIMAGE_DOS_HEADER pDH = NULL;
	PIMAGE_FILE_HEADER pFH = NULL;

	if(!isPEfile(ImageBase))
		return NULL;
	pDH = (PIMAGE_DOS_HEADER)ImageBase;
	pNtH = (PIMAGE_NT_HEADERS)((DWORD)pDH + pDH->e_lfanew);
	pFH = &pNtH->FileHeader;

	return pFH;

}

PIMAGE_OPTIONAL_HEADER GetOptionalHeader(LPVOID ImageBase)
{
	PIMAGE_NT_HEADERS pNtH = NULL;
	PIMAGE_DOS_HEADER pDH = NULL;
	PIMAGE_OPTIONAL_HEADER pOH = NULL;

	if(!isPEfile(ImageBase))
		return NULL;
	pDH = (PIMAGE_DOS_HEADER)ImageBase;
	pNtH = (PIMAGE_NT_HEADERS)((DWORD)pDH + pDH->e_lfanew);
	pOH = &pNtH->OptionalHeader;

	return pOH;
}