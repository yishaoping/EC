#!/usr/bin/env python3
"""Offline symbol-parser regressions; no compiler, converter or simulator."""
import unittest

from stage1_workload import parse_symbols


class SymbolTableTests(unittest.TestCase):
    def test_visibility_does_not_replace_size(self):
        for visibility in ('', '.hidden ', '.protected ', '.internal '):
            with self.subTest(visibility=visibility):
                names, sizes = parse_symbols(
                    '00000000800007b0 g     F .text\t0000000000000028 ' + visibility + '_exit\n'
                    '0000000080007e40 g     O .bss\t0000000000000100 ' + visibility + 'timer_flags\n')
                self.assertEqual(names['_exit'], 0x800007b0)
                self.assertEqual(sizes['_exit'], 0x28)
                self.assertEqual(names['timer_flags'], 0x80007e40)
                self.assertEqual(sizes['timer_flags'], 256)

    def test_header_and_flag_variants(self):
        names, sizes = parse_symbols(
            'test.riscv: file format elf64-littleriscv\n\nSYMBOL TABLE:\n'
            '0000000000008000 g       *ABS*\t0000000000000000 __stack_size\n'
            '0000000080007e00 l     O .bss\t0000000000000008 stage1_amo_words\n'
            '00000000800079f8 g     O .rodata\t0000000000000100 .hidden __clz_tab\n'
            '000000008005f9c8 l       .bss\t0000000000000000 __bss_end\n'
            '0000000000000000         *UND*\t0000000000000000 optional_symbol\n')
        self.assertEqual(names['__stack_size'], 0x8000)
        self.assertEqual(sizes['stage1_amo_words'], 8)
        self.assertEqual(sizes['__clz_tab'], 256)
        self.assertEqual(sizes['__bss_end'], 0)
        self.assertEqual(sizes['optional_symbol'], 0)
        self.assertEqual(len(names), 5)

    def test_bad_size_is_not_silently_skipped(self):
        with self.assertRaisesRegex(ValueError, 'invalid objdump symbol size for timer_flags'):
            parse_symbols('0000000080007e40 g O .bss not_hex .hidden timer_flags\n')


if __name__ == '__main__':
    unittest.main()
