import sys, time, math, re
import pandas as pd
from datetime import datetime

"""Bai lam co tham khao tu GPT va doc tai lieu tu [pandas.pydata.org]"""

df = pd.read_csv(sys.stdin, encoding='unicode_escape', encoding_errors='replace')

df['InvoiceDate'] = pd.to_datetime(df['InvoiceDate'])

lastBuy = df.groupby('CustomerID')['InvoiceDate'].max().reset_index()

minBuy = lastBuy['InvoiceDate'].min()

lastBuy['score'] = (lastBuy['InvoiceDate'] - minBuy).dt.days

lastBuy = lastBuy.sort_values(by='CustomerID', ascending=True).drop(columns='InvoiceDate')

lastBuy = pd.DataFrame(lastBuy)
print(lastBuy.to_string(index=False, header=True, justify='right'))

with open('result.txt', 'w', encoding='utf-8') as f:
    f.write(lastBuy.to_string(index=False, header=True, justify='right'))

# lastBuy.to_csv('result.txt', encoding='unicode_escape', index=False, lineterminator='\n')