///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
http://www.etlcpp.com

Copyright(c) 2017 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __ETL_USER_TYPE__
#define __ETL_USER_TYPE__

///\defgroup user_type user_type
/// Smart enumerations.<br>
/// A method of declaring a user type that also contains a set of constants,
/// but are not constrained to just those values.
/// This contrasts with 'enum_type', where the values are expected to <b>only</b> contain
/// those defined as constants.
/// <b>Declaring the enumeration.</b>
///\code
///   DECLARE_USER_TYPE(CompassDirection, int)
///   USER_TYPE(North, 0)
///   USER_TYPE(South, 180)
///   USER_TYPE(East,  90)
///   USER_TYPE(West,  270)
///   END_USER_TYPE
///\endcode
/// <b>Using the enumeration.</b>
///\code
/// CompassDirection direction;          // Default construction.
///
/// direction = CompassDirection::North; // Assignment from an enumeration constant;
///
/// int value = int(direction);          // Explicit conversion to 'int'.
/// int value = direction.get();
///
/// const int& value = direction.get();  // Bind to internal value.
///
/// direction = CompassDirection(value); // Explicit conversion from 'int'.
///
/// direction = CompassDirection(3);     // Explicit conversion from a value.
///
/// ++direction;                         // Manipulate the value;
/// direction -= 20;
///
/// direction = value;                   // Implicit conversion from 'int'. **** Compilation error ****
///
/// std::cout << "Direction = " << direction.c_str(); // Prints "Direction = North"
///\endcode
/// If a conversion to a string is not required then the 'ENUM_TYPE' declaration may be omitted.
/// In that case the c_str() function will return a "?". This will also be the case for any
/// enumeration value that does not have an ENUM_TYPE entry.
///\ingroup utilities

//*****************************************************************************
// The declaration of the structure.
//*****************************************************************************
#define DECLARE_USER_TYPE(TypeName, ValueType) \
  struct TypeName \
  { \
    enum enum_type \
    { \

//*****************************************************************************
// The predefined constants.
//*****************************************************************************
#define USER_TYPE(enum_name, value) \
      enum_name = value,

//*****************************************************************************
// The final section of the structure.
//*****************************************************************************
#define END_USER_TYPE \
    }; \

  typedef ValueType value_type; \
  TypeName() {} \
  TypeName(const TypeName &other) : value(other.value) {} \
  TypeName(enum_type value) : value(value) {} \
  TypeName& operator=(const TypeName &other) {value = other.value; return *this;} \
  explicit TypeName(value_type value) : value(static_cast<enum_type>(value)) {} \
  explicit operator value_type() const {return static_cast<value_type>(value);} \
  value_type& get() {return static_cast<value_type>(value);} \
  const value_type& get() const {return static_cast<value_type>(value);} \
  TypeName& operator ++() { ++value; return *this; } \
  TypeName operator ++(int) { TypeName temp(*this); TypeName::operator ++(); return temp; } \
  TypeName& operator --() { --value; return *this; }
  TypeName operator --(int) { TypeName temp(*this); TypeName::operator --(); return temp; } \
  TypeName& operator +=(value_type rhs) { value += rhs; return *this; } \
  TypeName& operator +=(const TypeName& rhs) { value += rhs.value; return *this; } \
  TypeName& operator -=(value_type rhs) { value -= rhs; return *this; } \
  TypeName& operator -=(const TypeName& rhs) { value -= rhs.value; return *this; } \
  TypeName& operator *=(value_type rhs) { value *= rhs; return *this; } \
  TypeName& operator *=(const TypeName& rhs) { value *= rhs.value; return *this; } \
  TypeName& operator /=(value_type rhs) { value /= rhs; return *this; } \
  TypeName& operator /=(const TypeName& rhs) { value /= rhs.value; return *this; } \
  TypeName& operator %=(value_type rhs) { value %= rhs; return *this; } \
  TypeName& operator %=(const TypeName& rhs) { value %= rhs.value; return *this; } \
  TypeName& operator &=(value_type rhs) { value &= rhs; return *this; } \
  TypeName& operator &=(const TypeName& rhs) { value &= rhs.value; return *this; } \
  TypeName& operator |=(value_type rhs) { value |= rhs; return *this; } \
  TypeName& operator |=(const TypeName& rhs) { value |= rhs.value; return *this; } \
  TypeName& operator ^=(value_type rhs) { value ^= rhs; return *this; } \
  TypeName& operator ^=(const TypeName& rhs) { value ^= rhs.value; return *this; } \
  TypeName& operator <<=(value_type rhs) { value <<= rhs; return *this; } \
  TypeName& operator >>=(value_type rhs) { value >>= rhs; return *this; } \
private: \
  value_type value; \
};

#endif
