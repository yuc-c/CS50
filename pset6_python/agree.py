s = input("Do you agree? ").lower() # .lower轉換為小寫

# 中間不論大小寫
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
