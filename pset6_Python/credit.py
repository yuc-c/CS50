# 作業3-2 credit

from cs50 import get_int

def main():
    card = get_int("Number: ")

    if valid_card(card):
        card_company(card)
    else:
        print("INVALID")
# 有效的卡片
def valid_card(card):
    sum = 0
    for i in range(len(str(card))):
        if i % 2 == 0:
            sum += card % 10
            card = card // 10
        else:
            if (card % 10) > 4:
                sum += (((card % 10) * 2) - 9)
                card = card // 10
            else:
                sum += ((card % 10) * 2)
                card = card // 10
    if sum % 10 == 0:
        return True
    else:
        return False

# 判斷卡片類型
def card_company(card):
    num = int(str(card)[0:2])

    if (num == 34 or num == 37) and len(str(card)) == 15:
        print("AMEX")
    elif 50 < num < 56 and len(str(card)) == 16:
        print("MASTERCARD")
    elif 39 < num < 50 and (len(str(card)) == 13 or len(str(card)) == 16):
        print("VISA")
    else:
        print("INVALID")

main()
