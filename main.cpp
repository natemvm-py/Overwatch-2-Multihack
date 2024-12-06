#include <Windows.h>
#include <string>
#include "utils.hpp"
#include "includes.hpp"
#include "SDK.hpp"
#include "Overwatch.hpp"
#include <io.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>






void MainThread() {
	using namespace OW;
	std::cout << "Overwatch 2 Multihack. Github @ natemvm-py\n";

	while (!SDK->Initialize())
	{
		std::cout << "Waiting for Overwatch..\n";//tg
		Sleep(2000);
	}

	// Checking memory read results
	auto viewMatrixVal = (SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base) ^ offset::offset_viewmatrix_xor_key) - offset::offset_viewmatrix_xor_key2;
	viewMatrixVal = viewMatrixVal + offset::offset_viewmatrix_xor_key ^ offset::offset_viewmatrix_xor_key2 - offset::offset_viewmatrix_xor_key3;
	viewMatrixVal = SDK->RPM<uint64_t>(viewMatrixVal + 0x20);
	viewMatrixVal = SDK->RPM<uint64_t>(viewMatrixVal + 0x58);
	viewMatrix_xor_ptr = viewMatrixVal + 0x140;
	auto view = SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base_test) + offset::offset_viewmatrix_ptr;
	viewMatrixPtr = view;


	if (viewMatrixVal == 0) {
		std::cerr << "Failed to read view matrix base address at " << std::hex << SDK->dwGameBase + offset::Address_viewmatrix_base << std::dec << std::endl;
	}
	else {
		std::cerr << "Read view matrix base: " << std::hex << viewMatrixVal << std::dec << std::endl;
	}

	// Starting threads
	std::cerr << "Loading threads...." << std::endl;
	_beginthread((_beginthread_proc_type)entity_scan_thread, 0, 0);
	Sleep(50);  // Small delay between thread starts

	_beginthread((_beginthread_proc_type)entity_thread, 0, 0);
	_beginthread((_beginthread_proc_type)viewmatrix_thread, 0, 0);
	Sleep(500);  // Small delay

	_beginthread((_beginthread_proc_type)aimbot_thread, 0, 0);
	_beginthread((_beginthread_proc_type)overlay_thread, 0, 0);
	_beginthread((_beginthread_proc_type)configsavenloadthread, 0, 0);
	Sleep(10);  // Small delay

	_beginthread((_beginthread_proc_type)looprpmthread, 0, 0);
	std::cerr << "Threads loaded successfully." << std::endl;
	std::cerr << "Cheat loaded. Insert to open/close menu. Enjoy." << std::endl;

	while (FindWindowA(skCrypt("TankWindowClass"), NULL))
	{
		// old but works
		//auto viewMatrixVal = (SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base) ^ offset::offset_viewmatrix_xor_key) - offset::offset_viewmatrix_xor_key2;
		//auto view = SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base_test) + offset::offset_viewmatrix_ptr;
		//viewMatrixPtr = view;
		//viewMatrix_xor_ptr = view + 0x40;

		// from uc still works
		auto viewMatrixVal = SDK->RPM<uint64_t>((SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base) ^ offset::offset_viewmatrix_xor_key) - offset::offset_viewmatrix_xor_key2);
		//viewMatrixVal = SDK->RPM<uint64_t>(viewMatrixVal + 0x20);
		viewMatrixVal = SDK->RPM<uint64_t>(viewMatrixVal + 0x58);
		viewMatrix_xor_ptr = viewMatrixVal + 0x140;
		auto view = SDK->RPM<uint64_t>(SDK->dwGameBase + offset::Address_viewmatrix_base_test) + offset::offset_viewmatrix_ptr;
		viewMatrixPtr = view;

		Sleep(100);
	}
}

int main()
{
	MainThread();
	using namespace OW;
	Sleep(10000);
	exit(0);
}
//  v63 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)(((qword_33EE770 + 0x77482B5E10C5793BLL) ^ 0xE17AD062B3DD5C8FuLL)
//- 0x34F79E3A5B5276BELL)
//+ 112LL))(((qword_33EE770 + 0x77482B5E10C5793BLL) ^ 0xE17AD062B3DD5C8FuLL) - 0x34F79E3A5B5276BELL);