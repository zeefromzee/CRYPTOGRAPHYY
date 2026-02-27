# code for greatest common factor
class gcd:
    def __init__(self, a, b):
        s, old_s = 0, 1
        t, old_t = 1, 0
        r, old_r = b, a

        while r != 0:
            q = old_r // r
            old_r, r = r, old_r - q * r
            old_s, s = s, old_s - q * s
            old_t, t = t, old_t - q * t

        self.bezout = (old_s, old_t)
        self.gcd = old_r
        self.quotients_by_gcd = (a // old_r, b // old_r)

        print("The Bézout coefficients:", self.bezout)
        print("Greatest common divisor:", self.gcd)
        print("quotients by gcd:", self.quotients_by_gcd)


gcd(66528, 52920)       #example values
