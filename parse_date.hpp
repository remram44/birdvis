/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
// Copyright 2011-2013 NYU Polytechnic School of Engineering.                      //
// Copyright 2010-2011 University of Utah.                                         //
//                                                                                 //
// Permission is hereby granted, free of charge, to any person obtaining a copy    //
// of this software and associated documentation files (the "Software"), to dea    //
// in the Software without restriction, including without limitation the rights    //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       //
// copies of the Software, and to permit persons to whom the Software is           //
// furnished to do so, subject to the following conditions:		           //
// 										   //
// The above copyright notice and this permission notice shall be included in	   //
// all copies or substantial portions of the Software.			           //
// 										   //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR	   //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,	   //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          // 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN       //
// THE SOFTWARE.                                                                   //
//                                                                                 // 
/////////////////////////////////////////////////////////////////////////////////////

#ifndef PARSE_DATE_H
#define PARSE_DATE_H

#include <cctype>
#include <ctime>
#include <cstdlib>

/**
 * Equivalent to strptime(s, "%Y-%m-%d", tm) (ISO 8601)
 */
char *parse_date(const char *s, struct tm *tm)
{
    char *pos;

    tm->tm_year = strtol(s, &pos, 10);
    if(pos == s || *pos != '-')
        return NULL;
    ++pos;

    s = pos;
    tm->tm_mon = strtol(s, &pos, 10);
    if(pos == s || *pos != '-')
        return NULL;
    ++pos;

    s = pos;
    tm->tm_mday = strtol(s, &pos, 10);
    if(pos == s)
        return NULL;

    return pos + 1;
}

#endif
