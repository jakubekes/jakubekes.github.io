$(window).on('load', function(){
	
$(document).ready(function(){
	
    $("#contents").load("/home.html", function(responseTxt, statusTxt, xhr){

  });
	
var routes = {
	'/home': function () { 
		contents_load_func("home")
	},	
	'/contact': function () { 
		contents_load_func("contact")
	},
	'/windows': function () { 
		contents_load_func("windows")
    },
	'/cpp': function () { 
		contents_load_func("cpp")
    },
	'/virtualization': function () { 
		contents_load_func("virtualization")
    },
	'/7zip_batch_extract': function () { 
		contents_load_func("7zip_batch_extract")
    },  	  
	'/7zip_batch_extract_de': function () { 
		contents_load_func("7zip_batch_extract_de")
    },
	'/screenshot_taker': function () { 
		contents_load_func("screenshot_taker")
    },  	  
	'/screenshot_taker_de': function () { 
		contents_load_func("screenshot_taker_de")
    },  	  
	'/hmac_sha256': function () { 
		contents_load_func("hmac_sha256")
    },  	  
	'/hmac_sha256_de': function () { 
		contents_load_func("hmac_sha256_de")
    },  	  
	'/efi_partition_access_windows': function () { 
		contents_load_func("efi_partition_access_windows")
    },  	  
	'/efi_partition_access_windows_de': function () { 
		contents_load_func("efi_partition_access_windows_de")
    },  	  
	'/qemu_basics': function () { 
		contents_load_func("qemu_basics")
    },  	  
	'/qemu_basics_de': function () { 
		contents_load_func("qemu_basics_de")
    } 	 	 	 	 	 	
};

	var router = Router(routes);
	router.init();
  
});
});

function contents_load_func(element_id){
	
	$("#contents").fadeOut(200);
	
	setTimeout(function(){
		$('#contents').html('')
		}, 500);
	
	setTimeout(function(){
	$("#contents").load("/"+element_id+".html"),
    $("#contents").fadeIn();	
	}, 500);
		
};

function change_code_height(){

	var height_px = $("#codeid").css("height");
	var height = height_px.substring(0,height_px.length-2);
	if(height <= 400){
		document.getElementById('codeid').style.height= '100%';
		document.getElementById('buttoncodeheightid').textContent= 'Scroll';
	} else {
		document.getElementById('codeid').style.height= '400px';
		document.getElementById('buttoncodeheightid').textContent= '100% height';
	}
}

/*$(document).on("click", "a", function() {
	contents_load_func(event.target.id);
})*/


