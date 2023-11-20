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
	'/all': function () { 
		contents_load_func("all")
	},
	'/windows': function () { 
		contents_load_func("windows")
    },
	'/cpp': function () { 
		contents_load_func("cpp")
    },
	'/linux': function () { 
		contents_load_func("linux")
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
    },  	  
	'/ps_batch_copy_from_zips': function () { 
		contents_load_func("ps_batch_copy_from_zips")
    },  	  
	'/ps_batch_copy_from_zips_de': function () { 
		contents_load_func("ps_batch_copy_from_zips_de")
    },  	  
	'/ffmpeg_video_tbnl_script': function () { 
		contents_load_func("ffmpeg_video_tbnl_script")
    },  	  
	'/ffmpeg_video_tbnl_script_de': function () { 
		contents_load_func("ffmpeg_video_tbnl_script_de")
    },  	  
	'/john-the-ripper_office_pwd_cracking': function () { 
		contents_load_func("john-the-ripper_office_pwd_cracking")
    },  	  
	'/john-the-ripper_office_pwd_cracking_de': function () { 
		contents_load_func("john-the-ripper_office_pwd_cracking_de")
    },  	  
	'/ps_hash_copy': function () { 
		contents_load_func("ps_hash_copy")
    },  	  
	'/ps_hash_copy_de': function () { 
		contents_load_func("ps_hash_copy_de")
    },  	  
	'/bootable_iso_and_physical_devices_with_VM': function () { 
		contents_load_func("bootable_iso_and_physical_devices_with_VM")
    },  	  
	'/bootable_iso_and_physical_devices_with_VM_de': function () { 
		contents_load_func("bootable_iso_and_physical_devices_with_VM_de")
    },  	  
	'/move_files_to_dirs_10k': function () { 
		contents_load_func("move_files_to_dirs_10k")
    },  	  
	'/move_files_to_dirs_10k_de': function () { 
		contents_load_func("move_files_to_dirs_10k_de")
    },  	  
	'/csv_divider': function () { 
		contents_load_func("csv_divider")
    },  	  
	'/csv_divider_de': function () { 
		contents_load_func("csv_divider_de")
    },  	  
	'/winhttp_api': function () { 
		contents_load_func("winhttp_api")
    },  	  
	'/winhttp_api_de': function () { 
		contents_load_func("winhttp_api_de")
    },  	  
	'/qt_multithreading_and_networking_basics': function () { 
		contents_load_func("qt_multithreading_and_networking_basics")
    },  	  
	'/qt_multithreading_and_networking_basics_de': function () { 
		contents_load_func("qt_multithreading_and_networking_basics_de")
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

function change_code_height(num){

	var div_id = "code_id_" + num;
	var button_id = "changeCodeHeightBtn_id_" + num;
	var height_px = $("#"+div_id).css("height");
	var height = height_px.substring(0,height_px.length-2);
	
	if(height <= 400){
		document.getElementById(div_id).style.height= '100%';
		document.getElementById(button_id).textContent= 'Scroll';
	} else {
		document.getElementById(div_id).style.height= '400px';
		document.getElementById(button_id).textContent= '100% height';
	}
}

/*function change_code_height(){

	var height_px = $("#codeid").css("height");
	var height = height_px.substring(0,height_px.length-2);
	if(height <= 400){
		document.getElementById('codeid').style.height= '100%';
		document.getElementById('buttoncodeheightid').textContent= 'Scroll';
	} else {
		document.getElementById('codeid').style.height= '400px';
		document.getElementById('buttoncodeheightid').textContent= '100% height';
	}
}*/

/*$(document).on("click", "a", function() {
	contents_load_func(event.target.id);
})*/


