(*[[
]]*)
FUNCTION SingleTest

#import "Crosstable.gvl"
#import "Resource1.gvl"

VAR_INPUT
	test_id : int;
	passed : bool;
	expected : string;
	obtained : string;
	test_cases : int;
END_VAR

VAR_IN_OUT
	test_index : int;
	test_level: UINT;
    test_counter : UDINT;
	test_loops : UDINT;
    test_errors : UDINT;
END_VAR

VAR
	ignored : bool;
	retval : dint;
	header : string;
	newline : string := '$n';
	m : int;
END_VAR

	(* 1/3 updating the test counters *)
	test_counter := test_counter + 1;
	if not passed then
		test_errors := test_errors + 1;
		Errors := Errors + 1;
		if test_level = TEST_UNKNOWN or test_level = TEST_PASSED then
			test_level := TEST_FAILED;
		end_if;
	end_if;

	(* 2/3 logging, if necessary *)
	if (not passed and LogLevel >= LOG_FAILED_TESTS) or (LogLevel = LOG_PASSED_TESTS) then
		header := time_to_string(tim_get());
		header := CONCAT(header, comma_blank, '"', test_names[test_id], '"');
		header := CONCAT(header, comma_blank, int_to_string(test_index));
		if passed then
			header := CONCAT(header, comma_blank, 'PASSED');
		else
			header := CONCAT(header, comma_blank, 'FAILED');
		end_if;

		 (* remember the 255 string len limit *)
		ignored := F_SYNC_WRITEFILE(header,                          log_file);
		ignored := F_SYNC_WRITEFILE(concat(comma_blank, 'expected'), log_file);
		ignored := F_SYNC_WRITEFILE(expected,                        log_file);
		m := len(expected);
		if (m = 255) then
			ignored := F_SYNC_WRITEFILE('<-LEN', log_file);
		end_if;
		ignored := F_SYNC_WRITEFILE(concat(comma_blank, 'obtained'), log_file);
		ignored := F_SYNC_WRITEFILE(obtained,                        log_file);
		m := len(obtained);
		if (m = 255) then
			ignored := F_SYNC_WRITEFILE('<-LEN', log_file);
		end_if;
		ignored := F_SYNC_WRITEFILE(newline,                         log_file);
		retval := F_FLUSH();
	end_if;

	(* 3/3 updating the loop counters *)
	test_index := test_index + 1;
	if test_index > test_cases then
		test_index := 1;
		test_loops := test_loops + 1;
	end_if;
	if test_loops >= Target and test_level = TEST_UNKNOWN then
		test_level := TEST_PASSED;
	end_if;

END_FUNCTION
