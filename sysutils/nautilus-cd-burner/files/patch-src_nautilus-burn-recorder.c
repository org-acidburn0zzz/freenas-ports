--- src/nautilus-burn-recorder.c.orig	Sun Nov 19 13:39:57 2006
+++ src/nautilus-burn-recorder.c	Sun Nov 19 13:40:58 2006
@@ -1153,10 +1153,10 @@ nautilus_burn_recorder_write_growisofs (
 
 	dev_str = NULL;
 	if (t->type == NAUTILUS_BURN_RECORDER_TRACK_TYPE_DATA) {
-		dev_str = g_strdup_printf ("%s=%s", nautilus_burn_drive_get_device (drive), t->contents.data.filename);
+		dev_str = g_strdup_printf ("%s=%s", nautilus_burn_drive_get_cdrecord_device (drive), t->contents.data.filename);
 		g_ptr_array_add (argv, dev_str);
 	} else {
-		g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_device (drive));
+		g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_cdrecord_device (drive));
 
 		/* mkisofs options */
 		if (ncb_mkisofs_supports_utf8 ()) {
@@ -1343,7 +1343,7 @@ nautilus_burn_recorder_write_cdrecord (N
 		g_ptr_array_add (argv, "cdrdao");
 		g_ptr_array_add (argv, "write");
 		g_ptr_array_add (argv, "--device");
-		g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_device (drive));
+		g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_cdrecord_device (drive));
 		g_ptr_array_add (argv, "--speed");
 		speed_str = g_strdup_printf ("%d", speed);
 		g_ptr_array_add (argv, speed_str);
@@ -1375,7 +1375,7 @@ nautilus_burn_recorder_write_cdrecord (N
 		if (speed != 0) {
 			g_ptr_array_add (argv, speed_str);
 		}
-		dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_device (drive));
+		dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
 		g_ptr_array_add (argv, dev_str);
 		if (flags & NAUTILUS_BURN_RECORDER_WRITE_DUMMY_WRITE) {
 			g_ptr_array_add (argv, "-dummy");
@@ -1486,7 +1486,7 @@ nautilus_burn_recorder_blank_disc_cdreco
 	argv = g_ptr_array_new ();
 	g_ptr_array_add (argv, "cdrecord");
 
-	dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_device (drive));
+	dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
 	g_ptr_array_add (argv, dev_str);
 	g_ptr_array_add (argv, "-v");
 
@@ -1560,7 +1560,7 @@ nautilus_burn_recorder_blank_disc_dvdrw_
 		g_ptr_array_add (argv, "growisofs");
 		g_ptr_array_add (argv, "-Z");
 
-		dev_str = g_strdup_printf ("%s=%s", nautilus_burn_drive_get_device (drive), "/dev/zero");
+		dev_str = g_strdup_printf ("%s=%s", nautilus_burn_drive_get_cdrecord_device (drive), "/dev/zero");
 		g_ptr_array_add (argv, dev_str);
 		g_ptr_array_add (argv, NULL);
 
@@ -1583,7 +1583,7 @@ nautilus_burn_recorder_blank_disc_dvdrw_
 			g_ptr_array_add (argv, blank_str);
 		}
 
-		dev_str = g_strdup_printf ("%s", nautilus_burn_drive_get_device (drive));
+		dev_str = g_strdup_printf ("%s", nautilus_burn_drive_get_cdrecord_device (drive));
 		g_ptr_array_add (argv, dev_str);
 		g_ptr_array_add (argv, NULL);
 
