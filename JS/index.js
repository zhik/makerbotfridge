  //set up the two FireBase vars (disabled due to system braking bug caused by overwrite)
			//ref.set({
			//	unlocked: null,
			//	closed: null,
			//})			
			// set null states of Vars in reg. JS
			var unlocked = '';
			var UnlockCode = '';
			var Door = '';
			var closed = '';
			var ref = new Firebase("https://fridgelock.firebaseio.com");
			
			
			// function that will send lockdoor signal, console.log is for debuging
			function lockdoor() {
				ref.update({
				unlocked: false,
			})			
			}
			// function that will send unlockdoor signal, console.log is for debuging
			function unlockdoor() {
				ref.update({
				unlocked: true,
			})	
			}



$( document ).ready(function() {
    console.log( "This is a console log test." );
 							ref.child('unlocked').on("value", function(snapshot) {
   unlocked = snapshot.val();
   console.log(unlocked);
   
if (unlocked == false) {var unlockedmessage = 'Locked' }
else if (unlocked == true) {var unlockedmessage = 'Unlocked'}
else {'everything broke send help'};
   document.getElementById("unlocked").innerHTML = unlockedmessage;
   
}, function (errorObject) {
  console.log("The read failed: " + errorObject.code);
});

			ref.child('closed').on("value", 
function(snapshot) {
   closed = snapshot.val();
   console.log(closed);
   
   if (closed == true) {var closedmessage = 'Closed' }
else if (closed == false) {var closedmessage = 'Open'}
else {'everything broke send help'};
   document.getElementById("closed").innerHTML = closedmessage;

   
}, function (errorObject) {
  console.log("The read failed: " + errorObject.code);
});


	
			
});