function summarizeSales(transactions) {
  return transactions.reduce((acc, current) => {
    if (current.quantity <= 0) return acc;
    
    const revenue = current.price * current.quantity;
    
    if (!acc[current.category]) {
      acc[current.category] = 0;
    }
    
    acc[current.category] += revenue;
    return acc;
  }, {});
}