/**
 * Copyright (C) 2018 Roberto Metere
 *
 * Redistribution and use of this script, with or without modification, is
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of this script must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 *  EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @author Roberto Metere
 */
#include <iostream>
#include <locale>
#include <codecvt>
#include "UpsideDown.h"

/**
 * Substitution to get corresponding upside-down
 */
std::vector<std::vector<wchar_t> > UpsideDown::convMap = {
  // Small letters
  { u'a', u'\u0250' }, // ɐ Latin Small Letter Turned A
  { u'b', 'q' },
  { u'c', u'\u0254' }, // ɔ Latin Small Letter Open O
  //     { u'd', 'p' },
  { u'e', u'\u01dd' }, // ǝ Latin Small Letter Turned E
  // { u'e', u'\u0259' },
  { u'f', u'\u025f' }, // ɟ Latin Small Letter Dotless J with Stroke
  { u'g', u'\u1d77' }, // ᵷ Latin Small Letter Turned G
  // { u'g', u'\u0253' },
  { u'h', u'\u0265' }, // ɥ Latin Small Letter Turned H
  { u'i', u'\u1d09' }, // ᴉ Latin Small Letter Turned I
  { u'j', u'\u23a7' }, // ⎧ Left curly bracket upper hook
  // { u'j', u'\u1e5b' }, // ṛ Latin small letter r with dot below
  // { u'j', u'\u027e' },
  { u'k', u'\u029e' }, // ʞ Latin Small Letter Turned K
  { u'l', u'\ua781' }, // ꞁ Latin Small Letter Turned L
  //   { u'l', u'\u0285' },
  //   { u'l', u'\u056c' },
  { u'm', u'\u026f' }, // ɯ Latin Small Letter Turned M
  { u'n', 'u' },
  //     { u'o', 'o' },
  { u'p', 'd' },
  //     { u'q', 'b' },
  { u'r', u'\u0279' }, // ɹ Latin Small Letter Turned R
  //     { u's', 's' },
  { u't', u'\u0287' }, // ʇ Latin Small Letter Turned T
  //     { u'u', 'n' },
  { u'v', u'\u028c' }, // ʌ Latin Small Letter Turned V
  { u'w', u'\u028d' }, // ʍ Latin Small Letter Turned W
  //     { u'x', 'x' },
  { u'y', u'\u028e' }, // ʎ Latin Small Letter Turned Y
  //     { u'z', 'z' },
  
  // Capital letters
  { u'A', u'\u2c6f' }, // Ɐ Latin Capital Letter Turned A
  { u'B', u'\u15fa' },
  { u'C', u'\u0186' }, // Ɔ Latin Capital Letter Open O
  { u'D', u'\u15e1' },
  { u'E', u'\u018e' }, // Ǝ Latin Capital Letter Reversed E
  //     { u'F', u'\u15b5' },
  { u'F', u'\u2132' }, // Ⅎ Turned Capital F
  // { u'F', u'\u07c3' },
  { u'G', u'\u2141' }, // ⅁ Turned Sans-Serif Capital G
  //     { u'H', 'H' },
  //     { u'I', 'I' },
  { u'J', u'\u017f' },
  { u'K', u'\ua7b0' }, // Ʞ Latin Capital Letter Turned K
  // { u'K', u'\u0c6b' },
  //     { u'K', u'\u22ca' },
  //     { u'L', u'\u2142' },
  { u'L', u'\ua780' }, // Ꞁ Latin Capital Letter Turned L
  // { u'L', u'\u2142' }, // ⅂ Turned Sans-Serif Capital L
  // { u'L', u'\u14a3' },
  { u'M', u'\u019c' }, // Ɯ Latin Capital Letter Turned M
  // { u'M', 'W' },
  //     { u'N', 'N' },
  //     { u'O', 'O' },
  { u'P', u'\u0500' },
  { u'Q', u'\u10e2' },
  { u'R', u'\u1d1a' }, // ᴚ Latin Letter Small Capital Turned R
  //     { u'S', 'S' },
  { u'T', u'\ua7b1' }, // Ʇ Latin Capital Letter Turned T
  // { u'T', u'\u22a5' },
  { u'U', u'\u2229' },
  { u'V', u'\u0245' }, // Ʌ Latin Capital Letter Turned V
  //     { u'W', 'M' },
  //     { u'X', 'X' },
  { u'Y', u'\u2144' }, // ⅄ Turned Sans-Serif Capital Y
  //     { u'Z', 'Z' },
  
  // Numbers
  //     { u'0', '0' },
  { u'1', u'\u01c0' },
//   { u'1', u'\u07c7' },
//   { u'1', u'\ua781' },
//   { u'1', u'\u21c2' },
  { u'2', u'\u218a' },
//   { u'2', u'\u2d52' },
  { u'3', u'\u218b' },
  { u'4', u'\u07c8' },
//   { u'5', u'\u0ea3' },
  { u'6', '9' },
  { u'7', u'\u14aa' },
//   { u'7', u'\u07c4' },
//   { u'7', u'\u2220' },
  //     { u'7', u'\u2c62' },
  //     { u'8', '8' },
  //     { u'9', '6' },
  
  // Puntuaction & symbols
  { u'.', u'\u02d9' },
  { u',', u'\u2018' },
  { u'\'', u'\u2e32' },
  //     { u':', ':' },
  { u';', u'\u2e35' },
  //     { u'-', '-' },
  { u'_', u'\u203e' },
  //     { u'#', '#' },
  { u'@', '@' },
  //     { u'+', '+' },
  //     { u'*', '*' },
  { u'?', u'\u00bf' },
  //     { u'=', '=' },
  { u')', '(' },
  //     { u'(', ')' },
  { u'/', '\\' },
  { u'&', u'\u214b' },
  //     { u'%', '%' },
  //     { u'$', '$' },
  { u'"', u'\u201e' },
  { u'!', u'\u00a1' }, //     { u'\u00a1', '!' },
  //     { u'|', '|' },
  //     { u'\\', '/' },
  { u'<', '>' }, //     { u'>', '<' },
  { u'[', ']' }, //     { u']', '[' },
  { u'{', '}' }, //     { u'}', '{' },
  //     { u'', '' },
  //     { u'', '' },
  //     { u'', '' },
  //     { u'', '' },
  
  
  // Some else
  { u'\u00df', u'\u0a88' } // ss german
  
  // Chess will be char32
};

/**
 * Constructor of upside down
 * @param convertme Array of strings to convert
 */
void UpsideDown::print(std::vector<std::wstring> convertme) {
  size_t i;
  std::wstring result;

  // Convert all strings
  for (i = 0L; i < convertme.size(); i++) {
    convertme[i] = UpsideDown::flip(convertme[i]);
  }

  // Create a result string
  result = convertme[convertme.size() - 1];
  for (i = convertme.size() - 2; i < convertme.size(); i--) {
    result += L" " + convertme[i];
    if (i == 0) {
      break;
    }
  }
  
  // Print out result
  std::wcout << result << std::endl;
}

/**
 * Flip a single wide string upside-down.
 * @param string String to convert
 * @return the same string as upside down
 */
std::wstring UpsideDown::flip(std::wstring string) {
  std::wstring result;

  wchar_t tmp;
  size_t i, j;

  for (i = string.length() - 1; ; i--) {
    tmp = string[i];
    for (j = 0; j < convMap.size(); j++) {
      if (tmp == convMap[j][0]) {
        tmp = convMap[j][1];
        break;
      } else if (tmp == convMap[j][1]) {
        tmp = convMap[j][0];
        break;
      }
    }
    result += tmp;
    if (i == 0) {
      break;
    }
  }

  return result;
}

/**
  * Main program, just print out upsided strings
  * @param argc Command line arguments size
  * @param argv Command line arguments
  */
int main (int argc, char *argv[]) {
  std::vector<std::wstring> args;
  std::wstring arg;
  std::locale::global(std::locale(""));
  std::wstring_convert<std::codecvt_utf8<wchar_t>> c2w;
  size_t i;
  
  // Print out an error if no strings to convert
  if (argc < 2) {
    std::cerr << "You must provide at least one argument" << std::endl;
    return 1;
  }

  // Read arguments as wide strings
  for(i = 1; i < (size_t) argc; i++) {
    arg = c2w.from_bytes(argv[i]);
    args.push_back(arg);
  }
  
  // Print them upside-down
  UpsideDown::print(args);
  
  return 0;
}
