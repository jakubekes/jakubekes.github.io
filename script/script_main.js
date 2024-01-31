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
		contents_load_func("categories/all")
	},
	'/windows': function () { 
		contents_load_func("categories/windows")
    },
	'/cpp': function () { 
		contents_load_func("categories/cpp")
    },
	'/linux': function () { 
		contents_load_func("categories/linux")
    },
	'/virtualization': function () { 
		contents_load_func("categories/virtualization")
    },
	'/7zip_batch_extract': function () { 
		contents_load_func("articles/7zip_batch_extract")
    },  	  
	'/7zip_batch_extract_de': function () { 
		contents_load_func("articles/7zip_batch_extract_de")
    },
	'/screenshot_taker': function () { 
		contents_load_func("articles/screenshot_taker")
    },  	  
	'/screenshot_taker_de': function () { 
		contents_load_func("articles/screenshot_taker_de")
    },  	  
	'/hmac_sha256': function () { 
		contents_load_func("articles/hmac_sha256")
    },  	  
	'/hmac_sha256_de': function () { 
		contents_load_func("articles/hmac_sha256_de")
    },  	  
	'/efi_partition_access_windows': function () { 
		contents_load_func("articles/efi_partition_access_windows")
    },  	  
	'/efi_partition_access_windows_de': function () { 
		contents_load_func("articles/efi_partition_access_windows_de")
    },  	  
	'/qemu_basics': function () { 
		contents_load_func("articles/qemu_basics")
    },  	  
	'/qemu_basics_de': function () { 
		contents_load_func("articles/qemu_basics_de")
    },  	  
	'/ps_batch_copy_from_zips': function () { 
		contents_load_func("articles/ps_batch_copy_from_zips")
    },  	  
	'/ps_batch_copy_from_zips_de': function () { 
		contents_load_func("articles/ps_batch_copy_from_zips_de")
    },  	  
	'/ffmpeg_video_tbnl_script': function () { 
		contents_load_func("articles/ffmpeg_video_tbnl_script")
    },  	  
	'/ffmpeg_video_tbnl_script_de': function () { 
		contents_load_func("articles/ffmpeg_video_tbnl_script_de")
    },  	  
	'/john-the-ripper_office_pwd_cracking': function () { 
		contents_load_func("articles/john-the-ripper_office_pwd_cracking")
    },  	  
	'/john-the-ripper_office_pwd_cracking_de': function () { 
		contents_load_func("articles/john-the-ripper_office_pwd_cracking_de")
    },  	  
	'/ps_hash_copy': function () { 
		contents_load_func("articles/ps_hash_copy")
    },  	  
	'/ps_hash_copy_de': function () { 
		contents_load_func("articles/ps_hash_copy_de")
    },  	  
	'/bootable_iso_and_physical_devices_with_VM': function () { 
		contents_load_func("articles/bootable_iso_and_physical_devices_with_VM")
    },  	  
	'/bootable_iso_and_physical_devices_with_VM_de': function () { 
		contents_load_func("articles/bootable_iso_and_physical_devices_with_VM_de")
    },  	  
	'/move_files_to_dirs_10k': function () { 
		contents_load_func("articles/move_files_to_dirs_10k")
    },  	  
	'/move_files_to_dirs_10k_de': function () { 
		contents_load_func("articles/move_files_to_dirs_10k_de")
    },  	  
	'/csv_divider': function () { 
		contents_load_func("articles/csv_divider")
    },  	  
	'/csv_divider_de': function () { 
		contents_load_func("articles/csv_divider_de")
    },  	  
	'/winhttp_api': function () { 
		contents_load_func("articles/winhttp_api")
    },  	  
	'/winhttp_api_de': function () { 
		contents_load_func("articles/winhttp_api_de")
    },  	  
	'/qt_multithreading_and_networking_basics': function () { 
		contents_load_func("articles/qt_multithreading_and_networking_basics")
    },  	  
	'/qt_multithreading_and_networking_basics_de': function () { 
		contents_load_func("articles/qt_multithreading_and_networking_basics_de")
    },  	  
	'/deluge_autoshutdown_python': function () { 
		contents_load_func("articles/deluge_autoshutdown_python")
    },  	  
	'/deluge_autoshutdown_python_de': function () { 
		contents_load_func("articles/deluge_autoshutdown_python_de")
    },  	  
	'/winhttp_file_download': function () { 
		contents_load_func("articles/winhttp_file_download")
    },  	  
	'/winhttp_file_download_de': function () { 
		contents_load_func("articles/winhttp_file_download_de")
    },  	  
	'/proxmox_backup_handling_on_windows_host': function () { 
		contents_load_func("articles/proxmox_backup_handling_on_windows_host")
    },  	  
	'/proxmox_backup_handling_on_windows_host_de': function () { 
		contents_load_func("articles/proxmox_backup_handling_on_windows_host_de")
    },  	  
	'/aoc': function () { 
		contents_load_func("categories/aoc")
    },  	  
	'/aoc_2021_day1': function () { 
		contents_load_func("aoc/aoc_2021_day1")
    },  	  
	'/aoc_2021_day2': function () { 
		contents_load_func("aoc/aoc_2021_day2")
    },  	  
	'/aoc_2021_day3': function () { 
		contents_load_func("aoc/aoc_2021_day3")
    },  	  
	'/aoc_2021_day4': function () { 
		contents_load_func("aoc/aoc_2021_day4")
    },  	  
	'/aoc_2021_day5': function () { 
		contents_load_func("aoc/aoc_2021_day5")
    },  	  
	'/aoc_2021_day6': function () { 
		contents_load_func("aoc/aoc_2021_day6")
    },  	  
	'/aoc_2021_day7': function () { 
		contents_load_func("aoc/aoc_2021_day7")
    },  	  
	'/aoc_2021_day8': function () { 
		contents_load_func("aoc/aoc_2021_day8")
    },  	  
	'/aoc_2021_day9': function () { 
		contents_load_func("aoc/aoc_2021_day9")
    },  	  
	'/aoc_2021_day10': function () { 
		contents_load_func("aoc/aoc_2021_day10")
    },  	  
	'/aoc_2021_day11': function () { 
		contents_load_func("aoc/aoc_2021_day11")
    },  	  
	'/aoc_2021_day12': function () { 
		contents_load_func("aoc/aoc_2021_day12")
    },  	  
	'/aoc_2022_day1': function () { 
		contents_load_func("aoc/aoc_2022_day1")
    },  	  
	'/aoc_2022_day2': function () { 
		contents_load_func("aoc/aoc_2022_day2")
    },  	  
	'/aoc_2022_day3': function () { 
		contents_load_func("aoc/aoc_2022_day3")
    },  	  
	'/aoc_2022_day4': function () { 
		contents_load_func("aoc/aoc_2022_day4")
    },  	  
	'/aoc_2022_day5': function () { 
		contents_load_func("aoc/aoc_2022_day5")
    },  	  
	'/aoc_2022_day6': function () { 
		contents_load_func("aoc/aoc_2022_day6")
    },  	  
	'/aoc_2022_day7': function () { 
		contents_load_func("aoc/aoc_2022_day7")
    },  	  
	'/aoc_2022_day8': function () { 
		contents_load_func("aoc/aoc_2022_day8")
    },  	  
	'/aoc_2022_day9': function () { 
		contents_load_func("aoc/aoc_2022_day9")
    },  	  
	'/aoc_2022_day10': function () { 
		contents_load_func("aoc/aoc_2022_day10")
    },  	  
	'/aoc_2022_day11': function () { 
		contents_load_func("aoc/aoc_2022_day11")
    },  	  
	'/aoc_2022_day12': function () { 
		contents_load_func("aoc/aoc_2022_day12")
    },  	  
	'/aoc_2022_day13': function () { 
		contents_load_func("aoc/aoc_2022_day13")
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


