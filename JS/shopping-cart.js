function processCart(cartItems) {
    const itemMap = {};

    cartItems.forEach(item => {
        const finalPrice = item.discount
            ? item.price * (1 - item.discount)
            : item.price;

        if (itemMap[item.id]) {
            itemMap[item.id].totalQuantity += item.quantity;
        } else {
            itemMap[item.id] = {
                id: item.id,
                name: item.name,
                category: item.category,
                price: finalPrice,
                totalQuantity: item.quantity
            };
        }
    });

    const categories = {};
    let rawSubtotal = 0;

    Object.values(itemMap).forEach(item => {
        rawSubtotal += item.price * item.totalQuantity;

        const { category, ...itemWithoutCategory } = item;

        if (!categories[category]) {
            categories[category] = [];
        }

        categories[category].push(itemWithoutCategory);
    });

    const subtotal = parseFloat(rawSubtotal.toFixed(2));
    const tax = parseFloat((subtotal * 0.07).toFixed(2));

    return {
        categories,
        subtotal,
        tax
    };
}