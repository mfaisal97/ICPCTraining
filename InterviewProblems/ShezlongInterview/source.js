//Data insertion O(n+m)
//Data query O(log(n)) or O(log(m)) or O(log(n)+log(m))
var DatabaseClinet = {
    "Data" : {
            "Clients" : null,           //it has name, age, ordersids
            "Orders" : null             //it has clientid, itemName, price
        },

    MergeClientsOrders : function(ClientsJson, OrdersJson){

        var importedClients = JSON.parse(ClientsJson);
        this.Data.Clients = new Map();
        for(const Client of importedClients){
            if(this.Data.Clients.has(Client.clientID)){
                alert(`Deplicate client ID ${user.clientID}`);
            } else {
                this.Data.Clients.set(Client.clientID, {"name" : Client.name, "age" : Client.age, "Orders" : new Set()});
            }
        }


        var importedOrders = JSON.parse(OrdersJson);
        this.Data.Orders = new Map();
        for (const Order of importedOrders){
            if(this.Data.Orders.has(Order.orderID)){
                alert(`Deplicate Order ID ${Order.orderID}`);
            }else {
                this.Data.Orders.set(Order.orderID, {"clientID" : Order.clientID, "itemName" : Order.itemName, "price" : Order.price});

                //!TO DO: check another more efficient way
                let ClientData = this.Data.Clients.get(Order.clientID);
                let ClientOrders = ClientData.Orders.add(Order.orderID);
                this.Data.Clients.set(Order.clientID, {"name" : ClientData.name, "age" : ClientData.age, "Orders" : ClientOrders});
            }
        }
    }, GetClientData : function (ClientID){
        return this.Data.Clients.get(ClientID);
    }, GetOrderData : function (OrderID){
        return this.Data.Orders.get(OrderID);
    }, GetClientWithOrder : function (OrderID){
        return this.Data.Clients.get(this.Data.Orders.get(OrderID).clientID);
    }
};
