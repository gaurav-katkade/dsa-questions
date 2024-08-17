#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long sum = 4*pow(10,9);
    cout<<(int)sum<<endl;
    cout<<sum;
    return 0;
}

//op -294967296
//4000000000

/*

On 16-bit systems: int might be 16 bits, while long is 32 bits.
On 32-bit systems: int is typically 32 bits, and long can also be 32 bits.
On 64-bit systems: int is usually 32 bits, but long might be 64 bits, depending on the platform (though this is less common on mainstream systems).


In C++, overflow occurs when a value is assigned to a variable that exceeds the maximum value that the variable's data type can hold. For example, when you store a large `long long` value into an `int` type, which has a smaller range, overflow can occur.

### Understanding Integer Overflow

**1. Data Type Size and Range:**
   - An `int` typically uses 4 bytes (32 bits) in memory. This gives it a range of values from \(-2^{31}\) to \(2^{31} - 1\), which is from \(-2,147,483,648\) to \(2,147,483,647\).
   - A `long long` typically uses 8 bytes (64 bits) in memory, which can store values from \(-2^{63}\) to \(2^{63} - 1\), giving it a much larger range than an `int`.

**2. The Overflow Process:**
   - When a value that exceeds the `int` range (like `4000000000`) is cast to `int`, the binary representation of the number is truncated to fit within the 32-bit limit of an `int`.
   - This truncation discards the higher-order bits that don't fit within 32 bits, effectively wrapping around the value in the available range.

### Example with `4000000000`:

- **Binary Representation:**
  - The binary representation of `4000000000` (which is \(2^{32} - 96\)) in 64 bits is:
    ```
    00000000 00000000 00000000 00000000 11101110 10011010 00000000 00000000
    ```
  - When casting to a 32-bit `int`, only the lower 32 bits are retained:
    ```
    11101110 10011010 00000000 00000000
    ```

- **Interpreting the Truncated Value:**
  - The binary `11101110 10011010 00000000 00000000` is interpreted as a negative number in 2's complement form (because the most significant bit is 1).
  - To find the value, you compute the 2's complement of the binary number, resulting in the decimal value `294967296`.
  - Since the most significant bit is 1, the actual value is negative: `-294967296`.

Thus, when you cast `4000000000` from `long long` to `int`, the overflow occurs, and the resulting value is `-294967296`, which is printed by the first `cout` statement.

### Why Does This Happen?
This behavior is intrinsic to how binary numbers are stored and interpreted in memory. Since the `int` data type can only hold a limited range of values, exceeding this range leads to truncation, and the truncated value is interpreted within the `int`'s range, resulting in overflow.
*/