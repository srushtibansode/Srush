document.addEventListener("DOMContentLoaded", function() {
    // Sample food items data
    const foodItems = [
        {
            id: 1,
            name: "Pizza Margherita",
            price: 100,//ain numeric price
            image: "./images/pizza.jpg", // Correct relative path
            description: "Classic pizza with tomato sauce and mozzarella cheese."
        },
        {
            id: 2,
            name: "Cheeseburger",
            price: 80,
            image: "./images/cheeseburger.jpg",
            description: "Juicy beef burger with cheddar cheese, lettuce, and tomato."
        },
        {
            id: 3,
            name: "Sushi Platter",
            price: 150,
            image: "./images/sushi.jpg",
            description: "Assorted sushi rolls with fresh fish and vegetables."
        }
    ];

    localStorage.setItem('products', JSON.stringify(foodItems));

    const products = JSON.parse(localStorage.getItem('products')) || [];
    const foodItemsContainer = document.getElementById("food-items");

    function displayFoodItems(items) {
        foodItemsContainer.innerHTML = "";
        items.forEach(item => {
            const foodItemCard = `
                <div class="col-md-4">
                    <div class="card food-item-card">
                        <img src="${item.image}" class="card-img-top" alt="${item.name}" onerror="this.src='images/default.jpg';">
                        <div class="card-body">
                            <h5 class="card-title">${item.name}</h5>
                            <p class="card-text">${item.description}</p>
                            <p class="card-text"><strong>${item.price}</strong></p>
                            <button class="btn btn-primary add-to-cart" 
                                data-image="${item.image}" 
                                data-name="${item.name}" 
                                data-id="${item.id}" 
                                data-price="${item.price}">
                                Add to Cart
                            </button>
                        </div>
                    </div>
                </div>
            `;
            foodItemsContainer.innerHTML += foodItemCard;
        });

        document.querySelectorAll('.add-to-cart').forEach(button => {
            button.addEventListener('click', function() {
                const item = {
                    id: this.getAttribute('data-id'),
                    name: this.getAttribute('data-name'),
                    image: this.getAttribute('data-image'),
                    price: parseFloat(this.getAttribute('data-price')) // Ensure numeric conversion
                };
                addToCart(item);
            });
        });
    }

    function updateCartCount() {
        const cart = JSON.parse(localStorage.getItem('cart')) || [];
        document.getElementById('cart-count').textContent = cart.length;
    }

    function addToCart(item) {
        const cart = JSON.parse(localStorage.getItem('cart')) || [];
        cart.push(item);
        localStorage.setItem('cart', JSON.stringify(cart));
        updateCartCount();
        alert("Item " + item.name + " added to cart!");
    }

    displayFoodItems(products);
    updateCartCount();
});
