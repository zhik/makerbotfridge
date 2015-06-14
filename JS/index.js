$( document ).ready(function() {
    console.log( "This is a console log test." );
});
			//set up the two FireBase vars (disabled due to system braking bug caused by overwrite)
			//ref.set({
			//	Locked: null,
			//	Open: null,
			//})			
			// set null states of Vars in reg. JS
			var Locked = '';
			var UnlockCode = '';
			var Door = '';
			var Open = '';
			var ref = new Firebase("https://fridgelock.firebaseio.com");
			ref.child('Locked').on("value", function(snapshot) {
   Locked = snapshot.val();
   console.log(Locked);
}, function (errorObject) {
  console.log("The read failed: " + errorObject.code);
});
			ref.child('Open').on("value", 
function(snapshot) {
   Locked = snapshot.val();
   console.log(Locked);
}, function (errorObject) {
  console.log("The read failed: " + errorObject.code);
});

			// function that will send lockdoor signal, console.log is for debuging
			function lockdoor() {
				ref.update({
				Locked: true,
			})			
			}
			// function that will send unlockdoor signal, console.log is for debuging
			function unlockdoor() {
				ref.update({
				Locked: false,
			})	
			}