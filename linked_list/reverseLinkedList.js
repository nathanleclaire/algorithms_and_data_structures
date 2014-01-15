var LinkedList = function(val) {
    this.val = val;
    this.next = undefined;
    var _this = this;
    this.add = function(val) {
        if (_this.next !== undefined) {
            _this.next.add(val);
        } else {
            _this.next = new LinkedList(val);
        }
    };
    this.reverse = function() {
        var curr = _this,
            prev = undefined,
            next;
        while (curr !== undefined) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            if (!curr) {
                return prev;
            }
        }
    };
};

var myLL = new LinkedList(5);
myLL.add(4);
myLL.add(3);
myLL.add(2);

var r = myLL.reverse();
console.log(r);
