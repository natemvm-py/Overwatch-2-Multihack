namespace OW {
    namespace offset {

        // Base

        static constexpr auto Address_viewmatrix_base = 0x34015A0;
        static constexpr auto Address_viewmatrix_base_test = 0x3AD5788;
        static constexpr auto Address_entity_base = 0x33EC7B0;
        static constexpr auto offset_viewmatrix_ptr = 0x7E0;
        static constexpr auto offset_viewmatrix_xor_key = 0x9E56FD54BA05CFB1ui64;
        static constexpr auto offset_viewmatrix_xor_key2 = 0x2088968737CF121Bi64;
        static constexpr auto offset_viewmatrix_xor_key3 = 0x34F79E3A5B5276BEi64;

        static constexpr auto changefov = 0x3550BB8;//SIG:F3 0F 11 05 ? ? ? ? 48 85 C9 74 ? 48 8D 55 ? E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 85 C0 74 ? 48 8B 15 ? ? ? ? 48 8D 0D ? ? ? ? FF D0 8B 43

        static constexpr auto SensitivePtr = 0x2064; //good
        static constexpr auto view_angle = 0x11A0;
        static constexpr auto Input = 0x115C;
    }
}

//decryptcomp:48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 56 48 83 ec ? 49 8b f1 49 8b e8
        //HeapManager SIG:84 C0 74 19 48 8B 0D ? ? ? ?(fifth sub)