# Leetcode Problem 166: Fraction to Recurring Decimal
# PYTHON CODE
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        
        res = []
        
        # Handle sign: negative if exactly one of them is negative
        if (numerator < 0) ^ (denominator < 0):
            res.append("-")
            
        numerator, denominator = abs(numerator), abs(denominator)
        
        # Integer part
        integer_part = numerator // denominator
        res.append(str(integer_part))
        
        remainder = numerator % denominator
        if remainder == 0:
            return "".join(res)
            
        res.append(".")
        
        # Map to store remainder -> index in res where its digit starts
        rem_map = {}
        
        while remainder != 0:
            if remainder in rem_map:
                # Insert '(' at the start of the repeating sequence and ')' at the end
                res.insert(rem_map[remainder], "(")
                res.append(")")
                break
                
            rem_map[remainder] = len(res)
            
            remainder *= 10
            res.append(str(remainder // denominator))
            remainder %= denominator
            
        return "".join(res)