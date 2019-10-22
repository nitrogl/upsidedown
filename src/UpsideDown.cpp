/**
 * Copyright (C) Roberto Metere. All rights reserved.
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
  { 'a', L'\u0250' },
  { 'b', 'q' },
  { 'c', L'\u0254' },
  //     { 'd', 'p' },
  { 'e', L'\u0259' },
  { 'f', L'\u025f' },
  { 'g', L'\u0253' },
  { 'h', L'\u0265' },
  { 'i', L'\u1d09' },
  { 'j', L'\u027e' },
  { 'k', L'\u029e' },
  { 'l', L'\ua781' },
  //     { 'l', L'\u0285' },
  //   { 'l', L'\u056c' },
  { 'm', L'\u026f' },
  { 'n', 'u' },
  //     { 'o', 'o' },
  { 'p', 'd' },
  //     { 'q', 'b' },
  { 'r', L'\u0279' },
  //     { 's', 's' },
  { 't', L'\u0287' },
  //     { 'u', 'n' },
  { 'v', L'\u028c' },
  { 'w', L'\u028d' },
  //     { 'x', 'x' },
  { 'y', L'\u028e' },
  //     { 'z', 'z' },
  
  // Capital letters
  { 'A', L'\u2c6f' },
  { 'B', L'\u15fa' },
  { 'C', L'\u0186' },
  { 'D', L'\u15e1' },
  { 'E', L'\u018e' },
  //     { 'F', L'\u15b5' },
  { 'F', L'\u07c3' },
  { 'G', L'\u2141' },
  //     { 'H', 'H' },
  //     { 'I', 'I' },
  { 'J', L'\u017f' },
  //     { 'K', L'\u22ca' },
  { 'K', L'\u0c6b' },
  //     { 'L', L'\u2142' },
  { 'L', L'\u14a3' },
  { 'M', 'W' },
  //     { 'N', 'N' },
  //     { 'O', 'O' },
  { 'P', L'\u0500' },
  { 'Q', L'\u10e2' },
  { 'R', L'\u1d1a' },
  //     { 'S', 'S' },
  { 'T', L'\u22a5' },
  { 'U', L'\u2229' },
  { 'V', L'\u0245' },
  //     { 'W', 'M' },
  //     { 'X', 'X' },
  { 'Y', L'\u2144' },
  //     { 'Z', 'Z' },
  
  // Numbers
  //     { '0', '0' },
  { '1', L'\u01c0' },
//   { '1', L'\u07c7' },
//   { '1', L'\ua781' },
  { '2', L'\u218a' },
  { '3', L'\u218b' },
  { '4', L'\u07c8' },
//   { '5', L'\u0ea3' },
  { '6', '9' },
  { '7', L'\u14aa' },
//   { '7', L'\u07c4' },
//   { '7', L'\u2220' },
  //     { '7', L'\u2c62' },
  //     { '8', '8' },
  //     { '9', '6' },
  
  // Puntuaction & symbols
  { '.', L'\u02d9' },
  { ',', L'\u2e32' }, //     { '\'', ',' },
  //     { ':', ':' },
  { ';', L'\u2e35' },
  //     { '-', '-' },
  { '_', L'\u203e' },
  //     { '#', '#' },
  { '@', '@' },
  //     { '+', '+' },
  //     { '*', '*' },
  { '?', L'\u00bf' },
  //     { '=', '=' },
  { ')', '(' },
  //     { '(', ')' },
  { '/', '\\' },
  { '&', L'\u214b' },
  //     { '%', '%' },
  //     { '$', '$' },
  { '"', L'\u201e' },
  { '!', L'\u00a1' }, //     { L'\u00a1', '!' },
  //     { '|', '|' },
  //     { '\\', '/' },
  { '<', '>' }, //     { '>', '<' },
  { '[', ']' }, //     { ']', '[' },
  { '{', '}' }, //     { '}', '{' },
  //     { '', '' },
  //     { '', '' },
  //     { '', '' },
  //     { '', '' },
  
  
  // Some else
  { L'\u00df', L'\u0a88' } // ss german
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
