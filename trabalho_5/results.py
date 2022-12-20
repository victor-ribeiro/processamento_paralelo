#%%
import pickle

with open("coisa.txt", "rb") as file:
    data = pickle.load(file, encoding="utf-8")
# %%
